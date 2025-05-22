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
#include "cLevelManager.h"
#include "cEditorManager.h"

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
	cPlayerCharacter mPlayerCharacter;
	cCameraManager mCameraManager;

	// Other managers
	cProjectileManager mProjectileManager;
	cLevelManager mLevelManager;
	cEditorManager mEditorManager;

public:
	// Constructors
	cGameManager(sf::RenderWindow& _GameWindow);
	~cGameManager() {};

	// Update Method
	void GameTick();














	// HMMMM singleton won't work if I pass in game window to constructor.... I'll leave that idea alone for now

	// Singleton crap....
	// Get the single instance of the class
	//static cPlayerUtils& GetInstance()
	//{
	//	static cGameManager instance; // Static instance created on first call
	//	return instance;
	//}
	// Delete copy constructor and assignment operator to prevent copying
	//cGameManager(const cGameManager&) = delete;
	//cGameManager& operator=(const cGameManager&) = delete;
};