#include "cLevelManager.h"
#include "cPlayerCharacter.h"
#include "cProjectileManager.h"


cLevelManager::cLevelManager(sf::RenderWindow& _Window, cEnemyManager& _EnemyManager, cProjectileManager& _ProjectileManager)
	: mLevel1(_Window)
	, mCurrentLevel(&mLevel1)
	, mFileInterface(mCurrentLevel)
	, mEnemyManager(_EnemyManager)
	, mProjectileManager(_ProjectileManager)
{
}

void cLevelManager::Update()
{
}

void cLevelManager::Draw()
{
	mCurrentLevel->Draw();
}

void cLevelManager::DebugDraw()
{
	mCurrentLevel->DebugDraw();
}

void cLevelManager::CheckPlayerWallCollisions(cPlayerCharacter& _Player)
{
	// Collision function will modify this
	sf::Vector2f CollisionDirection;
	// Get all fullwalls in level
	std::vector<cFullWall*>& FullWallColliderList = mCurrentLevel->GetFullWallColliderList();

	// Check collisions
	for (size_t i = 0; i < FullWallColliderList.size(); ++i) {
		FullWallColliderList[i]->CheckCollideWithPlayer(_Player, CollisionDirection);
	}
}

void cLevelManager::CheckEnemyBulletCollision()
{
	// Collision function will modify this
	sf::Vector2f CollisionDirection;

	// Get all playerbullets
	std::array<cBullet, 15>& PlayerBulletList = mProjectileManager.GetPlayerBulletList();
	std::vector<cEnemyCharacter*>& EnemyList = mEnemyManager.GetEnemyList();
	// Check each bullet for collision
	for (cBullet& bullet : PlayerBulletList)
	{
		// Save some calculation if bullet is not active
		if (bullet.mIsActive) break;

		// Check collision with each enemy
		for (cEnemyCharacter* enemy : EnemyList)
		{
			bullet.CheckCollisionWithEnemy(*enemy, CollisionDirection);
		}
	}
}

void cLevelManager::AddFullWall(cFullWall* _FullWallCollider)
{
	mCurrentLevel->AddFullWallToList(_FullWallCollider);
}

void cLevelManager::AddHalfWall(cHalfWall* _HalfWallCollider)
{

}

void cLevelManager::SaveLevel()
{
	mCurrentLevel->SaveLevel(mFileInterface);
}

void cLevelManager::LoadLevel()
{
	mCurrentLevel->LoadLevel(mFileInterface);
}

