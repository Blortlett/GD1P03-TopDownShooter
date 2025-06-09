/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cGameManager]
Description : [This class handles game tick and calls update methods]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cPlayerCharacter.h"
#include "cCameraManager.h"
#include "cProjectileManager.h"
#include "cEditorManager.h"
#include "cLevelManager.h"
#include "cPickupManager.h"
#include "cGameStateManager.h"
#include "cEnemyManager.h"
#include "cViewUI.h"

class cGameManager
{
private:
	// Time Variables
	sf::Clock mClock;
	sf::Time mDeltaTime;
	float mDeltaSeconds = 0.f;

	// Game Window
	sf::RenderWindow& mGameWindow;

	// Player Character
	cPlayerInput mPlayerInput;
	cCameraManager mCameraManager;
	cPlayerCharacter mPlayerCharacter;

	// Projectile Manager
	cProjectileManager mProjectileManager;
	// Pickupable Manager
	cPickupManager mPickupManager;

	// Enemy Manager
	cEnemyManager mEnemyManager;

	// Level Manager
	cLevelManager mLevelManager;

	// Level Won & Bullet Collision checks
	cGameStateManager mGameStateManager;

	// Draw tool
	cEditorManager mEditorManager;

	cViewUI mGameplayUI;


	
	void OnSaveLevel();
	void OnLoadLevel();

	void CheckToggleDebugMode();
	bool mIsDebugButtonPressed = false;

public:
	// Constructors
	cGameManager(sf::RenderWindow& _GameWindow);
	~cGameManager() {};
	void RefreshDeltaTime();

	// Call this on new level load
	void SpawnEnemies();

	// Update Method
	void GameTick();

	cGameStateManager& GetGameStateManager() { return mGameStateManager; }
};