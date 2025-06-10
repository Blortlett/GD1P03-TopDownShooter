/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPauseMenu]
Description : [cPauseMenu encapsulates the pause menu UI to be displayed while game is paused]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "PauseMenuButtons.h"

class cPauseMenu
{
private:
	float mMidScreenPosX = 960.f;
	float mMidScreenPosY = 540.f;

	// Menu stuff
	sf::RenderWindow& mWindow;
	sf::Text mMenuTitleText;
	sf::RectangleShape mMenuBackground;

	// Menu Buttons
	cResumeButton mResumeButton;
	cOptionsButton mOptionsButton;
	cQuitGameButton mQuitGameButton;
	cDebugMenuButton mDebugMenuButton;

	bool mPauseButtonPressed = false;

public:
	cPauseMenu(sf::RenderWindow& window);

	bool mIsActive = false;
	void Update();
};