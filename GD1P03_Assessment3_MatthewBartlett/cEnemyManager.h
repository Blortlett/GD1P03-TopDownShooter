#pragma once
#include "cEnemyCharacter.h"
#include "cPickupManager.h"
#include <vector>

class cEnemySpawner;

class cEnemyManager
{
private:
	// List of enemies to update
	std::vector<cEnemyCharacter*> mEnemyList;

	sf::RenderWindow& mRenderWindow; // Game window

	// Game Managers
	cPlayerCharacter& mPlayerReference;
	cProjectileManager& mProjectileManager;
	cPickupManager& mPickupManager;

public:
	cEnemyManager(cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, cPickupManager& _PickupManager, cPlayerCharacter& _PlayerCharacter);
	~cEnemyManager();

	void SetupEnemyList(std::vector<cEnemySpawner*>& _EnemySpawnPositions);
	void RespawnEnemies();

	void Update(float _DeltaTime);

	std::vector<cEnemyCharacter*>& GetEnemyList();
};