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
{
}

void cGameManager::GameTick()
{
	// Get Delta seconds each while loop
	RefreshDeltaTime();

	// Update Player
	mPlayerCharacter.Update(mGameWindow, mDeltaSeconds);
	mPlayerCharacter.Draw(mGameWindow);
}

void cGameManager::RefreshDeltaTime()
{
	// Get & store Delta Seconds
	mDeltaTime = mClock.restart();
	mDeltaSeconds = mDeltaTime.asSeconds();
}