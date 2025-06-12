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
#include "PauseMenuButtons.h"
#include "cSharedUtils.h"
#include "cPauseMenu.h"
#include "cGameSettings.h"
#include "cGameManager.h"


//	-= Resume Button =-
cResumeButton::cResumeButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu)
	: cButtonUI(position, size)
	, mText(mBodyFont, "RESUME", 6U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mPauseMenu(_PauseMenu)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cResumeButton::OnButtonClick()
{
	// Deactivate menu
	cGameSettings::GetInstance().ToggleGamePaused(false);
}

void cResumeButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}



//	-= Open Options Menu Button =-
cOptionsButton::cOptionsButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu)
	: cButtonUI(position, size)
	, mText(mBodyFont, "OPTIONS", 7U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mPauseMenu(_PauseMenu)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cOptionsButton::OnButtonClick()
{
	// Open Options Menu
	cGameSettings::GetInstance().ToggleOptionsMenu(true);
}

void cOptionsButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}



//	-= Quit Game Button =-
cQuitGameButton::cQuitGameButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu, cGameStateManager& _GameStateManager)
	: cButtonUI(position, size)
	, mText(mBodyFont, "QUIT", 4U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mPauseMenu(_PauseMenu)
	, mGameStateManager(_GameStateManager)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cQuitGameButton::OnButtonClick()
{
	// Quit to main menu
	std::cout << "Quit button pressed... returning to main menu" << std::endl;
	mGameStateManager.UnloadLevels();
	cGameSettings::GetInstance().SetGameState(EGameState::MainMenu);
}

void cQuitGameButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}



//	-= Open Debug Menu Button =-
cDebugMenuButton::cDebugMenuButton(sf::Vector2f position, sf::Vector2f size, cPauseMenu& _PauseMenu)
	: cButtonUI(position, size)
	, mText(mBodyFont, "DEBUG", 5U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mPauseMenu(_PauseMenu)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cDebugMenuButton::OnButtonClick()
{
	// Open Options Menu
	cGameSettings::GetInstance().ToggleDebugMenu(true);
}

void cDebugMenuButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}
