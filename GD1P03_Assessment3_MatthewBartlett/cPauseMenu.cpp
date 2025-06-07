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

cPauseMenu::cPauseMenu(sf::RenderWindow& window)
	: mMenuTitleText(cSharedUtils::GetInstance().mButtonFont, "PAUSED", 7U)
	, mWindow(window)
	//, mMainMenuButton(platformList, editorToolbar)
{
	mMenuTitleText.setCharacterSize(70);
	sf::Vector2f titlePosition = sf::Vector2f(sf::Vector2f(1366, 768) / 2.0f);
	titlePosition.y -= 140;
	mMenuTitleText.setPosition(titlePosition);
	mMenuTitleText.setOrigin(mMenuTitleText.getGlobalBounds().size / 2.0f);

	// SetBackground
	mMenuBackground.setSize(sf::Vector2f(375, 500));
	mMenuBackground.setPosition(sf::Vector2f(1366, 768) / 2.0f);
	mMenuBackground.setOrigin(mMenuBackground.getSize() / 2.0f);
	mMenuBackground.setOutlineColor(sf::Color::Black);
	mMenuBackground.setFillColor(sf::Color(50, 50, 50, 178));
}

cPauseMenu::~cPauseMenu()
{
}

void cPauseMenu::Update()
{
	//// Draw Menu objects
	//mWindow.draw(mMenuBackground);
	//mWindow.draw(mMenuTitleText);
	//// Draw&Update Menu Buttons
	//mResumeButton.Update(mWindow);
	//mResumeButton.Draw(mWindow);
	//mMainMenuButton.Update(mWindow);
	//mMainMenuButton.Draw(mWindow);
}
