/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEnemyManager]
Description : [This class manages updating, spawning, drawing and other functionality for enemy characters]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cEnemyManager.h"
#include "cEnemySpawner.h"

cEnemyManager::cEnemyManager(cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, cPickupManager& _PickupManager, cPlayerCharacter& _PlayerCharacter)
	: mRenderWindow(_GameWindow)
	, mPlayerReference(_PlayerCharacter)
	, mProjectileManager(_ProjectileManager)
	, mPickupManager(_PickupManager)
{
}

cEnemyManager::~cEnemyManager()
{
	for (cEnemyCharacter* weapon : mEnemyList)
	{
		delete weapon;
	}
	mEnemyList.clear();
}

void cEnemyManager::Update(float _DeltaTime)
{
	for (cEnemyCharacter* enemy : mEnemyList)
	{
		enemy->Update(_DeltaTime);
		enemy->Draw();
	}
}

std::vector<cEnemyCharacter*>& cEnemyManager::GetEnemyList()
{
	return mEnemyList;
}

void cEnemyManager::ClearEnemyList()
{
	// Delete each enemy
	for (cEnemyCharacter* enemy : mEnemyList)
	{
		delete enemy;
	}
	// Clear the vector
	mEnemyList.clear();
}

void cEnemyManager::SetupEnemyList(std::vector<cEnemySpawner*>& _EnemySpawnPositions)
{
	// Clear List
	ClearEnemyList();

	// Repopulate enemies
	for (cEnemySpawner* enemySpawner : _EnemySpawnPositions)
	{
		cEnemyCharacter* newEnemy = new cEnemyCharacter(enemySpawner->GetPosition(), mProjectileManager, mPickupManager, mRenderWindow, mPlayerReference);
		mEnemyList.push_back(newEnemy);
		
	}
}

void cEnemyManager::RespawnEnemies()
{
	for (cEnemyCharacter* Enemy : mEnemyList)
	{
		Enemy->RespawnCharacter();
		Enemy->RespawnEnemy();
	}
}
