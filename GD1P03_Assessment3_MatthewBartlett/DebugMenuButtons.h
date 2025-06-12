/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cDebugMenuButtons]
Description : [This class holds funtionality to handle/display debugMenu buttons UI in game]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cButtonUI.h"
#include "cGameStateManager.h"

class cDebugMenuUI;

// Toggles Infinite Ammo
class cInfiniteAmmo : public cButtonUI
{
public:
	cInfiniteAmmo(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cDebugMenuUI& mDebugMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

// Toggles God Mode
class cGodMode : public cButtonUI
{
public:
	cGodMode(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cDebugMenuUI& mDebugMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

// Skips the current level
class cSkipLevel : public cButtonUI
{
public:
	cSkipLevel(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu, cGameStateManager& _GameStateManager);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cGameStateManager& mGameStateManager;
	cDebugMenuUI& mDebugMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};

// Returns to Pause Menu
class cBackFromDebugMenuButton : public cButtonUI
{
public:
	cBackFromDebugMenuButton(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu);

	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	cDebugMenuUI& mDebugMenu;
	sf::Font& mBodyFont;
	sf::Text mText;
};