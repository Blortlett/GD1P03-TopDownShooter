/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cViewUI]
Description : [This class holds funtionality to draw/display in game UI]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include "cAmmoUI.h"
#include "cPauseMenu.h"
#include "cOptionsMenuUI.h"
#include "cDebugMenuUI.h"
#include "cLevelCompleteUI.h"

class cPlayerCharacter;
class cCameraManager;

class cViewUI
{
private:
	sf::View mUICanvas;
	// UI Elements
	cAmmoUI mAmmoUI;
	cPauseMenu mPauseMenuUI;
	cOptionsMenuUI mOptionsMenuUI;
	cDebugMenuUI mDebugMenuUI;
	cLevelCompleteUI mLevelCompleteUI;

	// Game Components
	sf::RenderWindow& mGameWindow;
	cPlayerCharacter& mPlayerCharacter;
	cGameStateManager& mGameStateManager;
	cCameraManager& mCameraManager;

public:
	cViewUI(sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter, cGameStateManager& _GameStateManager, cCameraManager& mCameraManager);

	void Update(float _DeltaTime);
	void Draw();
};