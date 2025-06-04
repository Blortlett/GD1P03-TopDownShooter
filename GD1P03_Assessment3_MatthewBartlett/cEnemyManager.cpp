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

void cEnemyManager::SetupEnemyList(std::vector<cEnemySpawner*>& _EnemySpawnPositions)
{
	std::cout << "Spawning Enemies! :)" << std::endl;
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
	}
}
