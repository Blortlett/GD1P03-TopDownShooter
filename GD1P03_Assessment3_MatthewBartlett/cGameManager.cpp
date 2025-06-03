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

cGameManager::cGameManager(sf::RenderWindow& _GameWindow)
	: mGameWindow(_GameWindow)
	, mCameraManager(mPlayerCharacter, _GameWindow)
	, mPlayerCharacter(sf::Vector2f(0.f, 0.f), mProjectileManager, _GameWindow, mCameraManager.GetCameraView(), mPlayerInput)
	, mProjectileManager(_GameWindow)
	, mLevelManager(_GameWindow)
	, mEditorManager(_GameWindow, mLevelManager, mCameraManager.GetCameraView())
	, mPickupManager(_GameWindow)
	, mEnemyManager(mProjectileManager, mGameWindow, mPickupManager, mPlayerCharacter)
{

}

void cGameManager::GameTick()
{
	// Get Delta seconds each while loop
	RefreshDeltaTime();

	// Update Camera // Must happen before drawing anything
	mCameraManager.Update(mDeltaSeconds);

	// Update Level
	mLevelManager.Draw();
	mLevelManager.CheckPlayerWallCollisions(mPlayerCharacter);
	mLevelManager.CheckBulletToEnemyCollision(mProjectileManager, mEnemyManager);

	// Update Enemies
	mEnemyManager.Update(mDeltaSeconds);

	// Update Player
	mPlayerCharacter.Update(mDeltaSeconds);

	// Update ProjectileManager
	mProjectileManager.Update(mDeltaSeconds);

	// Update Pickupables
	mPickupManager.Update(mDeltaSeconds);

	// Draw Player last!!
	mPlayerCharacter.Draw();


	// Debug Mode
	CheckToggleDebugMode();
	if (cGameSettings::GetInstance().IsDebugActive())
	{
		mEditorManager.UpdateCursor();
		mEditorManager.DrawCursorToScreen(mGameWindow);
		mLevelManager.DebugDraw();
	}

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