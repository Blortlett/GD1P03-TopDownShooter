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

cGameManager::cGameManager(sf::RenderWindow& _GameWindow)
	: mGameWindow(_GameWindow)
	, mPlayerCharacter(mProjectileManager, _GameWindow, mCameraManager.GetCameraView())
	, mCameraManager(mPlayerCharacter, _GameWindow)
	, mProjectileManager(_GameWindow)
	, mLevelManager(_GameWindow)
	, mEditorManager(_GameWindow, mLevelManager)
{
}

void cGameManager::GameTick()
{
	// Get Delta seconds each while loop
	RefreshDeltaTime();

	// Update Camera // Must happen before drawing anything
	mCameraManager.Update(mDeltaSeconds);

	// Draw Level
	mLevelManager.Draw();

	// Update Player
	mPlayerCharacter.Update(mDeltaSeconds);
	mPlayerCharacter.Draw();

	// Update ProjectileManager
	mProjectileManager.Update(mDeltaSeconds);

}

void cGameManager::RefreshDeltaTime()
{
	// Get & store Delta Seconds
	mDeltaTime = mClock.restart();
	mDeltaSeconds = mDeltaTime.asSeconds();
}