#include "cEnemyManager.h"

cEnemyManager::cEnemyManager(cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter)
	: mRenderWindow(_GameWindow)
	, mPlayerReference(_PlayerCharacter)
	, mProjectileManager(_ProjectileManager)
{
	// Create single enemy to muck around with
	cEnemyCharacter* newEnemy = new cEnemyCharacter(sf::Vector2f(-60.f, -160.f), _ProjectileManager, _GameWindow, _PlayerCharacter);
	mEnemyList.push_back(newEnemy);
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
