#pragma once
#include "cEnemyCharacter.h"
#include <vector>

class cEnemyManager
{
private:
	// List of enemies to update
	std::vector<cEnemyCharacter*> mEnemyList;

	// Game Managers
	sf::RenderWindow& mRenderWindow; // Game window
	cPlayerCharacter& mPlayerReference;
	cProjectileManager& mProjectileManager;
public:
	cEnemyManager(cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter);
	~cEnemyManager() {}

	void Update(float _DeltaTime);

	std::vector<cEnemyCharacter*>& GetEnemyList();
};