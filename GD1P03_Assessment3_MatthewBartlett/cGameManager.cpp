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
#include "cGameManager.h"
#include "cGameSettings.h"
#include "cPlayerSpawner.h"


cGameManager::cGameManager(sf::RenderWindow& _GameWindow)
	: mGameWindow(_GameWindow)
	, mCameraManager(mPlayerCharacter, _GameWindow)
	, mPlayerCharacter(sf::Vector2f(300.f, 300.f), mProjectileManager, _GameWindow, mCameraManager.GetCameraView(), mPlayerInput)
	, mProjectileManager(_GameWindow)
	, mLevelManager(_GameWindow)
	, mEditorManager(_GameWindow, mLevelManager, mCameraManager.GetCameraView())
	, mPickupManager(mPlayerCharacter, _GameWindow)
	, mEnemyManager(mProjectileManager, mGameWindow, mPickupManager, mPlayerCharacter)
	, mGameStateManager(mEnemyManager, mProjectileManager, mLevelManager, mPlayerCharacter, mPickupManager)
	, mGameplayUI(mGameWindow, mPlayerCharacter, mGameStateManager, mCameraManager)
{
	//std::cout << "cGameManager Constructor: Transition to next level" << std::endl;
	mGameStateManager.TransitionToNextLevel();
}

void cGameManager::GameTick()
{
	// Get Delta seconds each while loop
	RefreshDeltaTime();

	// Set Camera View & handle Camera		// Must happen before drawing anything
	mCameraManager.Update(mDeltaSeconds);

	// Update Level
	mLevelManager.Update(mDeltaSeconds);
	mLevelManager.Draw();
	mLevelManager.CheckPlayerWallCollisions(mPlayerCharacter);
	mGameStateManager.Update(mDeltaSeconds);


	// Check if player has reached level exit
	bool isAtExit = mLevelManager.CheckLevelExit(mPlayerCharacter);
	bool isLevelComplete = cLevelProgressTracker::GetInstance().CheckLevelComplete();
	bool isPlayerAlive = mPlayerCharacter.IsAlive();

	if (isAtExit && isLevelComplete && isPlayerAlive && !mLevelExitTriggered)
	{
		mLevelExitTriggered = true;
		mLevelExitDelay = LEVEL_EXIT_COOLDOWN;
		//std::cout << "Player touched level exit: Preparing transition..." << std::endl;
	}

	// Log when level becomes complete
	if (isLevelComplete && !mLevelExitTriggered)
	{
		sf::Vector2f playerPos = mPlayerCharacter.GetPosition();
		sf::Vector2f exitPos = mLevelManager.GetLevelExitPosition();

		/*std::cout << "=== LEVEL COMPLETE ===" << std::endl;
		std::cout << "Player Position: (" << playerPos.x << ", " << playerPos.y << ")" << std::endl;
		std::cout << "Exit Position: (" << exitPos.x << ", " << exitPos.y << ")" << std::endl;
		std::cout << "Is At Exit: " << (isAtExit ? "TRUE" : "FALSE") << std::endl;
		std::cout << "Is Alive: " << (isPlayerAlive ? "TRUE" : "FALSE") << std::endl;
		std::cout << "======================" << std::endl;*/
	}

	// Process the delayed transition
	if (mLevelExitTriggered)
	{
		mLevelExitDelay -= mDeltaSeconds;

		if (mLevelExitDelay <= 0.f)
		{
			// Final check - only transition if player is still alive
			if (mPlayerCharacter.IsAlive())
			{
				//std::cout << "Transitioning to next level" << std::endl;
				mGameStateManager.TransitionToNextLevel();
			}
			else
			{
				//std::cout << "Transition cancelled - player died" << std::endl;
			}
			mLevelExitTriggered = false;
		}
	}

	// Update Enemies
	mEnemyManager.Update(mDeltaSeconds);

	// Update Player
	mPlayerCharacter.Update(mDeltaSeconds);

	// Update ProjectileManager
	mProjectileManager.Update(mDeltaSeconds);

	// Update Pickupables
	mPickupManager.Update(mDeltaSeconds);

	// Draw Player last!! Ontop of anything else (Except debug & UI stuff)
	mPlayerCharacter.Draw();


	// Debug Mode
	CheckToggleDebugMode();
	if (cGameSettings::GetInstance().IsDebugActive())
	{
		// Editor Draw tools... removed from release because the player cannot be trusted
		//mEditorManager.UpdateToolMode();
		//mEditorManager.UpdateCursor();
		//mEditorManager.DrawCursorToScreen(mGameWindow);
		mLevelManager.DebugDraw();
	}

	// Set UI View & Handle Gameplay UI
	mGameplayUI.Update(mDeltaSeconds);
	mGameplayUI.Draw();
	
	// Save/Load Level Detection
	OnSaveLevel();
	OnLoadLevel();
}

void cGameManager::RefreshDeltaTime()
{
	// Get & store Delta Seconds
	mDeltaTime = mClock.restart();
	mDeltaSeconds = mDeltaTime.asSeconds();
}

void cGameManager::OnSaveLevel()
{
	if (mPlayerInput.IsSaveButtonPressed())
	{
		mLevelManager.SaveLevel();
	}
}

void cGameManager::OnLoadLevel()
{
	if (mPlayerInput.IsLoadButtonPressed())
	{
		mLevelManager.LoadLevel();
	}
}

void cGameManager::SpawnEnemies()
{
	// Pass enemy spawner list into EnemyManager to set up enemies for a newly loaded level
	mEnemyManager.SetupEnemyList(mLevelManager.GetEnemySpawnerList());
}

void cGameManager::CheckToggleDebugMode()
{
	if (mPlayerInput.IsDebugButtonPressed())
	{
		if (!mIsDebugButtonPressed)
			cGameSettings::GetInstance().ToggleDebugMode();

		mIsDebugButtonPressed = true;
	}
	else
	{
		mIsDebugButtonPressed = false;
	}
}