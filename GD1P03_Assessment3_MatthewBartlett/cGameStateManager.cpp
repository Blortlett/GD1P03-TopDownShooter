#include "cGameStateManager.h"

cGameStateManager::cGameStateManager(cEnemyManager& _EnemyManager, cProjectileManager& _ProjectileManager, cLevelManager& _LevelManager)
    : mEnemyManager(_EnemyManager)
    , mProjectileManager(_ProjectileManager) 
    , mLevelManager(_LevelManager)
{
}

void cGameStateManager::TrackLevelComplete() {
    /// !!! We can probably tick enemies down one by one on kill instead of checking every frame !!!
    // Check will be changed to false if any Enemies remain alive
    bool AllEnemiesDeadCheck = true;
    for (cEnemyCharacter* enemy : mEnemyManager.GetEnemyList()) {
        if (enemy->IsAlive())
            AllEnemiesDeadCheck = false;
    }
    if (AllEnemiesDeadCheck) {
        std::cout << "All enemies defeated. You may now exit the level." << std::endl;
        mLevelComplete = true;
    }
}

// Sorry bout the birds nest
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

    // Check each bullet for collision
    for (cBullet& bullet : PlayerBulletList) {

        // Skip loop iteration if bullet is not active
        if (!bullet.mIsActive) continue;

        // Check collision with each enemy
        for (cEnemyCharacter* enemy : EnemyList) {
            // Don't check collision if enemy is dead
            if (!enemy->IsAlive()) continue; //
            // check collision
            if (bullet.CheckCollisionWithEnemy(*enemy, CollisionDirection)) {
                // If bullet hit enemy, deactivate bullet
                bullet.mIsActive = false;
            }
        }

        // Check collision with each fullwall
        for (cFullWall* Wall : WallList)
        {
            if (bullet.GetCollider().CheckCollision(Wall->GetCollider(), CollisionDirection, 1.0f))
            {
                bullet.mIsActive = false;
            }
        }
    }
}