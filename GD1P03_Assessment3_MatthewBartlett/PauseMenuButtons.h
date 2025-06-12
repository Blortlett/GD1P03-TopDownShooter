/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [PauseMenuButtons]
Description : [PauseMenuButtons provides buttons for the player to push for pause menu functionality]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cButtonUI.h"

class cGameStateManager;
class cPauseMenu;

class cResumeButton : public cButtonUI
{
public:
	cResumeButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cPauseMenu& mPauseMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

class cOptionsButton : public cButtonUI
{
public:
	cOptionsButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cPauseMenu& mPauseMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

// Returns to main menu
class cQuitGameButton : public cButtonUI
{
public:
	cQuitGameButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu, cGameStateManager& _GameStateManager);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cPauseMenu& mPauseMenu;
	cGameStateManager& mGameStateManager;

	sf::Font& mBodyFont;
	sf::Text mText;
};

class cDebugMenuButton : public cButtonUI
{
public:
	cDebugMenuButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cPauseMenu& mPauseMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};