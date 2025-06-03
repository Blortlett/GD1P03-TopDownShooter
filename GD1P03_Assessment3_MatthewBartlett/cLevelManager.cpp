#include "cLevelManager.h"
#include "cPlayerCharacter.h"
#include "cProjectileManager.h"
#include "cEnemyManager.h"
#include "cExitTrigger.h"



cLevelManager::cLevelManager(sf::RenderWindow& _Window)
	: mLevel1(_Window)
	, mCurrentLevel(&mLevel1)
	, mFileInterface(mCurrentLevel)
{
	mFileInterface.LoadLevelByName("Level1");
}

void cLevelManager::Draw()
{
	mCurrentLevel->Draw();
}

void cLevelManager::DebugDraw()
{
	mCurrentLevel->DebugDraw();
}

void cLevelManager::TrackLevelComplete(cEnemyManager& _EnemyManager)
{
	/// !!! We can probably tick enemies down one by one on kill instead of checking every frame !!!
	// I am too tired to write new code that is good. Bed time, come back tomorrow
	// Check will be changed to false if any Enemies remain alive
	bool AllEnemiesDeadCheck = true;
	for (cEnemyCharacter* enemy : _EnemyManager.GetEnemyList())
	{
		if (enemy->IsAlive())
			AllEnemiesDeadCheck = false;
	}

	if (AllEnemiesDeadCheck)
	{
		mLevelComplete = true;
	}
}

void cLevelManager::CheckPlayerWallCollisions(cPlayerCharacter& _Player)
{
	// Collision function will modify this
	sf::Vector2f CollisionDirection;
	// Get all full walls in level
	std::vector<cFullWall*>& FullWallColliderList = mCurrentLevel->GetFullWallColliderList();

	// Check full wall collisions
	for (size_t i = 0; i < FullWallColliderList.size(); ++i) {
		FullWallColliderList[i]->CheckCollideWithPlayer(_Player, CollisionDirection);
	}

	cExitDoor* ExitDoor = mCurrentLevel->GetExitDoor();
	if (ExitDoor)
	{
		ExitDoor->CheckCollideWithPlayer(_Player, CollisionDirection);
	}
}

void cLevelManager::CheckBulletToEnemyCollision(cProjectileManager& _ProjectileManager, cEnemyManager& _EnemyManager)
{
	// Collision function will modify this
	sf::Vector2f CollisionDirection;

	// Get all playerbullets
	std::array<cBullet, 15>& PlayerBulletList = _ProjectileManager.GetPlayerBulletList();
	std::vector<cEnemyCharacter*>& EnemyList = _EnemyManager.GetEnemyList();
	// Check each bullet for collision
	for (cBullet& bullet : PlayerBulletList)
	{
		// Skip loop iteration if bullet is not active
		if (!bullet.mIsActive) continue;

		// Check collision with each enemy
		for (cEnemyCharacter* enemy : EnemyList)
		{
			// check collision
			if (bullet.CheckCollisionWithEnemy(*enemy, CollisionDirection))
			{ // If bullet hit enemy, deactivate bullet // sorry for such indentation lol
				bullet.mIsActive = false;
			}
		}
	}
}

void cLevelManager::AddFullWall(cFullWall* _FullWallCollider)
{
	if (!mCurrentLevel) return; // Error check
	mCurrentLevel->AddFullWallToList(_FullWallCollider);
}

void cLevelManager::AddHalfWall(cHalfWall* _HalfWallCollider)
{
	if (!mCurrentLevel) return; // Error check
	mCurrentLevel->AddHalfWallToList(_HalfWallCollider);
}

void cLevelManager::AddExitDoor(cExitDoor* _ExitDoorObject)
{
	if (!mCurrentLevel) return; // Error check
	mCurrentLevel->AddExitDoorToLevel(_ExitDoorObject);
}

void cLevelManager::AddExitZone(cExitTrigger* _ExitZoneObject)
{
	if (!mCurrentLevel) return; // Error check
	mCurrentLevel->AddExitZoneToLevel(_ExitZoneObject);
}

void cLevelManager::TryDeleteWall(sf::Vector2f pointCollision)
{
	// Get FullWall List
	std::vector<cFullWall*>& FullWallList = mCurrentLevel->GetFullWallColliderList();
	// Ruffle through it
	for (size_t i = 0; i < FullWallList.size(); ++i)
	{
		// If point collides with the wall
		if (FullWallList[i]->CheckCollideWithPoint(pointCollision))
		{
			// Delete it
			delete FullWallList[i];
			// Remove item from list
			FullWallList.erase(FullWallList.begin() + i);
		}
	}
}

void cLevelManager::SaveLevel()
{
	mCurrentLevel->SaveLevel(mFileInterface);
}

void cLevelManager::LoadLevel()
{
	mCurrentLevel->LoadLevel(mFileInterface);
}

