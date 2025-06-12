/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cApplicationManager]
Description : [This class handles displaying main menu or game states]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cGameManager.h"
#include "cMainMenu.h"



class cApplicationManager
{
private:
	sf::RenderWindow mGameWindow;
	cGameManager mGameManager;

	cMainMenu mMainMenu;
	sf::View mDefaultView;
public:
	cApplicationManager();
	~cApplicationManager();

	void Run();
};