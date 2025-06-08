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

	// Game window
	sf::RenderWindow& mRenderWindow; 

	// Game Managers
	cPlayerCharacter& mPlayerReference;
	cProjectileManager& mProjectileManager;
	cPickupManager& mPickupManager;

	// Clears list of enemies
	void ClearEnemyList();
public:
	cEnemyManager(cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, cPickupManager& _PickupManager, cPlayerCharacter& _PlayerCharacter);
	~cEnemyManager();

	// Sets up a new list of enemies
	void SetupEnemyList(std::vector<cEnemySpawner*>& _EnemySpawnPositions);
	
	// resets all enemies in list
	void RespawnEnemies();

	void Update(float _DeltaTime);

	std::vector<cEnemyCharacter*>& GetEnemyList();
};