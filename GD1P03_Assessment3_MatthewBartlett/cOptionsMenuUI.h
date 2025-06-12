/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cOptionsMenuUI]
Description : [cOptionsMenuUI encapsulates the options UI to provide in game options to player]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/


#pragma once
#include "OptionsMenuButtons.h"

class cOptionsMenuUI
{
private:
	float mMidScreenPosX = 960.f;
	float mMidScreenPosY = 540.f;

	// Menu stuff
	sf::RenderWindow& mWindow;
	sf::Text mMenuTitleText;
	sf::RectangleShape mMenuBackground;

	// Menu Buttons
	cMuteSFX mMuteSFXButton;
	cMuteMusic mMuteMusicButton;
	cVSyncButton mVSyncButton;
	cBackButton mBackButton;


public:
	cOptionsMenuUI(sf::RenderWindow& window);

	bool mIsActive = false;
	void Update();

	// vsync enabled
	bool mIsVsyncEnabled = false;
	void ToggleVsync();
};