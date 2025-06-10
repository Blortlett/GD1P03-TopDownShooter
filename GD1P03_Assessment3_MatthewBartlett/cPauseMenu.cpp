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
#include "cPauseMenu.h"
#include "cGameSettings.h"
#include "cSharedUtils.h"

cPauseMenu::cPauseMenu(sf::RenderWindow& window)
	: mMenuTitleText(cSharedUtils::GetInstance().mTitleFont, "PAUSED", 7U)
	, mWindow(window)
	, mResumeButton({ mMidScreenPosX, 400.f }, { 250.f, 80.f }, *this)
	, mOptionsButton({ mMidScreenPosX, 510.f }, { 250.f, 80.f }, *this)
	, mQuitGameButton({ mMidScreenPosX, 620.f }, { 250.f, 80.f }, *this)
	, mDebugMenuButton({ mMidScreenPosX, 730.f }, { 250.f, 80.f }, *this)
{
	mMenuTitleText.setCharacterSize(70);
	sf::Vector2f titlePosition = sf::Vector2f(sf::Vector2f(mMidScreenPosX, 260.f));
	mMenuTitleText.setPosition(titlePosition);
	mMenuTitleText.setOrigin(mMenuTitleText.getGlobalBounds().size / 2.0f);

	// SetBackground
	mMenuBackground.setSize(sf::Vector2f(450, 700));
	mMenuBackground.setPosition(sf::Vector2f(mMidScreenPosX, mMidScreenPosY));
	mMenuBackground.setOrigin(mMenuBackground.getSize() / 2.0f);
	mMenuBackground.setOutlineColor(sf::Color::Black);
	mMenuBackground.setFillColor(sf::Color(50, 50, 50, 178));
}

void cPauseMenu::Update()
{
	// Press Escape to pause/unpause game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && !mPauseButtonPressed)
	{
		cGameSettings::GetInstance().ToggleGamePaused();
		mPauseButtonPressed = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		mPauseButtonPressed = false;
	}

	// If game not paused, return early dont display pause menu
	if (!cGameSettings::GetInstance().GetIsGamePaused() || cGameSettings::GetInstance().GetIsOptionsMenuOpen()) return;

	// Draw Menu background
	mWindow.draw(mMenuBackground);
	mWindow.draw(mMenuTitleText);

	// Draw&Update Menu Buttons
	mResumeButton.Update(mWindow);
	mResumeButton.Draw(mWindow);

	mOptionsButton.Update(mWindow);
	mOptionsButton.Draw(mWindow);

	mQuitGameButton.Update(mWindow);
	mQuitGameButton.Draw(mWindow);

	// Only draw/update debug menu button if game is in debug mode
	if (cGameSettings::GetInstance().IsDebugActive())
	{
		mDebugMenuButton.Update(mWindow);
		mDebugMenuButton.Draw(mWindow);
	}
}
