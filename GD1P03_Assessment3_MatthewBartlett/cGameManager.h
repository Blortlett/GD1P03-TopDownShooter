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
#include "cEnemyManager.h"
#include "cEditorManager.h"
#include "cLevelManager.h"
#include "cPickupManager.h"

class cGameManager
{
private:
	// Time Variables
	void RefreshDeltaTime();
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

	// Draw tool
	cEditorManager mEditorManager;


	
	void OnSaveLevel();
	void OnLoadLevel();

	void CheckToggleDebugMode();
	bool mIsDebugButtonPressed = false;

public:
	// Constructors
	cGameManager(sf::RenderWindow& _GameWindow);
	~cGameManager() {};

	// Update Method
	void GameTick();
};