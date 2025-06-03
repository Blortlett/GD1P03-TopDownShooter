#include "cEnemyManager.h"

cEnemyManager::cEnemyManager(cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, cPickupManager& _PickupManager, cPlayerCharacter& _PlayerCharacter)
	: mRenderWindow(_GameWindow)
	, mPlayerReference(_PlayerCharacter)
	, mProjectileManager(_ProjectileManager)
	, mPickupManager(_PickupManager)
{
	// Create single enemy to muck around with
	cEnemyCharacter* newEnemy = new cEnemyCharacter(sf::Vector2f(-60.f, -160.f), _ProjectileManager, _PickupManager, _GameWindow, _PlayerCharacter);
	mEnemyList.push_back(newEnemy);
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
