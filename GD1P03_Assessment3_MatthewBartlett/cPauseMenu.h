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
#include "cApplicationManager.h"
//#include "cResumeButton.h"
//#include "cReturnToMainMenu.h"

class cPauseMenu
{
private:
	// Menu stuff
	sf::RenderWindow& mWindow;
	sf::Text mMenuTitleText;
	sf::RectangleShape mMenuBackground;
	// Menu Buttons
	/*cResumeButton mResumeButton;
	cReturnToMainMenu mMainMenuButton;*/

public:
	cPauseMenu(sf::RenderWindow& window);
	~cPauseMenu();

	bool mIsActive = false;
	void Update();
};