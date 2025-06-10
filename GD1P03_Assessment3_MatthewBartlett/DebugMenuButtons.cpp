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
#include "DebugMenuButtons.h"
#include "cSharedUtils.h"
#include "cDebugMenuUI.h"
#include "cGameSettings.h"


//	-= Toggle Unlimited Ammo =-
cInfiniteAmmo::cInfiniteAmmo(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu)
	: cButtonUI(position, size)
	, mText(mBodyFont, "INF AMMO", 8U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mDebugMenu(_DebugMenu)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cInfiniteAmmo::OnButtonClick()
{
	// Toggle Infinite Ammo
	cGameSettings::GetInstance().mIsInfiniteAmmoActive = !cGameSettings::GetInstance().mIsInfiniteAmmoActive;
}

void cInfiniteAmmo::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}



//	-= Toggle God Mode =-
cGodMode::cGodMode(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu)
	: cButtonUI(position, size)
	, mText(mBodyFont, "GOD MODE", 8U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mDebugMenu(_DebugMenu)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cGodMode::OnButtonClick()
{
	// Enable GodMode
	cGameSettings::GetInstance().mIsGodModeActive = !cGameSettings::GetInstance().mIsGodModeActive;
}

void cGodMode::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}



//	-= Skips current Level =-
cSkipLevel::cSkipLevel(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu, cGameStateManager& _GameStateManager)
	: cButtonUI(position, size)
	, mText(mBodyFont, "SKIP LEVEL", 10U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mDebugMenu(_DebugMenu)
	, mGameStateManager(_GameStateManager)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cSkipLevel::OnButtonClick()
{
	// Skips the current level
	mGameStateManager.TransitionToNextLevel();
}

void cSkipLevel::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}



//	-= Back to pause menu Button =-
cBackFromDebugMenuButton::cBackFromDebugMenuButton(sf::Vector2f position, sf::Vector2f size, cDebugMenuUI& _DebugMenu)
	: cButtonUI(position, size)
	, mText(mBodyFont, "BACK", 4U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mDebugMenu(_DebugMenu)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cBackFromDebugMenuButton::OnButtonClick()
{
	// Return to pause menu
	cGameSettings::GetInstance().ToggleDebugMenu(false);
}

void cBackFromDebugMenuButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}