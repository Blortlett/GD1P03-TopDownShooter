/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cMainMenu]
Description : [cMainMenu encapsulates the main menu UI to be displayed on load / return to main menu]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include "cPlayButton.h"
#include "cGameStateManager.h"
#include <iostream>


class cMainMenu
{
public:
	cMainMenu(sf::RenderWindow& renderWindow, cGameStateManager& _GameStateManager);
	~cMainMenu();
	void Update();
	bool mIsActive = true;
private:
	// Render Window
	sf::RenderWindow& mRenderWindow;

	// Title
	sf::Text mTitleText;
	sf::Text mSubTitleText;
	sf::Vector2f mTitlePosition = sf::Vector2f(1366 / 2, (768 / 2) - 280);

	// Buttons
	sf::Vector2f mButtonSize = sf::Vector2f(300, 100);
	sf::Vector2f mPlayButtonPosition = sf::Vector2f(1366 / 2, 450);
	cPlayButton mPlayButtonUI;
};