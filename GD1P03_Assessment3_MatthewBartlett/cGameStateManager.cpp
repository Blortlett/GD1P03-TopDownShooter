#include "cGameStateManager.h"
#include "cEnemyManager.h"

#include "cPlayerCharacter.h"
#include "cPlayerSpawner.h"
#include "cPickupManager.h"

cGameStateManager::cGameStateManager(cEnemyManager& _EnemyManager, cProjectileManager& _ProjectileManager, cLevelManager& _LevelManager, cPlayerCharacter& _PlayerCharacter, cPickupManager& _PickupManager)
    : mEnemyManager(_EnemyManager)
    , mProjectileManager(_ProjectileManager) 
    , mLevelManager(_LevelManager)
    , mPlayerCharacter(_PlayerCharacter)
    , mPickupManager(_PickupManager)
{
}

void cGameStateManager::Update(float _DeltaTime)
{
    CheckBulletCollision();
    CheckEnemyWallCollision();
    CheckResetLevel(_DeltaTime);
}

void cGameStateManager::CheckBulletCollision() 
{
    // Collision function will modify this
    sf::Vector2f CollisionDirection;

    // Get all playerbullets
    std::array<cBullet, 15>& PlayerBulletList = mProjectileManager.GetPlayerBulletList();
    // Get all enemies
    std::vector<cEnemyCharacter*>& EnemyList = mEnemyManager.GetEnemyList();
    // Get all walls
    std::vector<cFullWall*>& WallList = mLevelManager.GetFullWallList();

    // Check each player bullet for collision with each enemy & wall collisions
    for (cBullet& bullet : PlayerBulletList) {

        // Skip loop iteration if bullet is not active
        if (!bullet.GetIsActive()) continue;

        // Check collision with each enemy
        for (cEnemyCharacter* enemy : EnemyList) {
            // Don't check collision if enemy is dead
            if (!enemy->IsAlive()) continue; //
            // check collision
            if (bullet.CheckCollisionWithEnemy(*enemy, CollisionDirection)) {
                // If bullet hit enemy, deactivate bullet
                bullet.DisableBullet();
            }
        }

        // Check collision with each fullwall
        for (cFullWall* Wall : WallList)
        {
            if (bullet.GetCollider().CheckCollision(Wall->GetCollider(), CollisionDirection, 0.0f))
            {
                // Deactivate bullet if hit fullwall
                bullet.DisableBullet();
            }
        }
    }

    // Get enemy bullet list
    std::array<cBullet, 20>& EnemyBulletList = mProjectileManager.GetEnemyBulletList();
    // Check each enemy bullet for collision with player & each wall
    for (cBullet& bullet : EnemyBulletList)
    {
        // Skip loop iteration if bullet is not active
        if (!bullet.GetIsActive()) continue;

        // Check collision with each fullwall
        for (cFullWall* Wall : WallList)
        {
            if (bullet.GetCollider().CheckCollision(Wall->GetCollider(), CollisionDirection, 0.0f))
            {
                // Deactivate bullet if hit fullwall
                bullet.DisableBullet();
            }
        }

        // Don't check for player collision if player is dead
        if (!mPlayerCharacter.mAlive) continue;

        //Check Collision with player
        if (bullet.CheckCollisionWithPlayer(mPlayerCharacter, CollisionDirection))
        {
            // if bullet hit player, deactivate bullet
            bullet.DisableBullet();
            // Kill Player
            mPlayerCharacter.OnBulletCollision(CollisionDirection);
        }
    }
}

void cGameStateManager::CheckEnemyWallCollision()
{
    sf::Vector2f CollisionDirection;

    // Get Wall lists
    std::vector<cFullWall*>& FullWallList = mLevelManager.GetFullWallList();
    std::vector<cHalfWall*>& HalfWallList = mLevelManager.GetHalfWallList();
    // Get Enemy List
    std::vector<cEnemyCharacter*>& EnemyList = mEnemyManager.GetEnemyList();

    for (cEnemyCharacter* Enemy : EnemyList)
    {
        // Check full wall collisions
        for (size_t i = 0; i < FullWallList.size(); ++i) {
            FullWallList[i]->CheckCollideWithPlayer(*Enemy, CollisionDirection);
        }
        // Check half wall collisions
        for (size_t i = 0; i < HalfWallList.size(); ++i) {
            HalfWallList[i]->CheckCollideWithPlayer(*Enemy, CollisionDirection);
        }
    }
}

void cGameStateManager::InitializeLevelEnemies()
{
    // Get enemy spawner object list
    std::vector<cEnemySpawner*>& enemySpawnerList = mLevelManager.GetEnemySpawnerList();

    // Spawn Enemies
    mEnemyManager.SetupEnemyList(enemySpawnerList);

    // Set enemy count in level progress tracker singleton
    cLevelProgressTracker::GetInstance().OnLoadSetEnemyCount(enemySpawnerList.size());
}

void cGameStateManager::TransitionToNextLevel()
{
    // Clear dropped weapons
    mPickupManager.ClearDrops();

    // Load the next level
    mLevelManager.AdvanceToNextLevel();

    // Set up enemies for level
    InitializeLevelEnemies();

    // Reset level complete flag
    mLevelComplete = false;

    // Reset player position
    cPlayerSpawner* playerSpawner = mLevelManager.GetCurrentLevel()->GetPlayerSpawner();
    if (playerSpawner)
    {
        mPlayerCharacter.SetPosition(playerSpawner->GetPosition());
        mPlayerCharacter.RevivePlayer();
    }
}

void cGameStateManager::CheckResetLevel(float _DeltaTime)
{
    // Only reset level if player is dead
    if (mPlayerCharacter.mAlive) return;

    // Countdown timer before level resets
    mPlayerDeathTimer -= _DeltaTime;

    // -= Reset Code =-
    if (mPlayerDeathTimer <= 0.f)
    {
        // Reset the current level
        mEnemyManager.RespawnEnemies(); // Reset enemies

        // Reset level complete flag
        mLevelComplete = false;
        // Revive player
        mPlayerCharacter.RevivePlayer();

        // Reset enemy death counter so door doesnt open early
        cLevelProgressTracker::GetInstance().ResetEnemyCount();

        // Reset player position
        cPlayerSpawner* playerSpawner = mLevelManager.GetCurrentLevel()->GetPlayerSpawner();
        if (playerSpawner)
        {
            mPlayerCharacter.SetPosition(playerSpawner->GetPosition());
        }

        // Reset death timer
        mPlayerDeathTimer = mPlayerDeathTimerMax;
    }
}
