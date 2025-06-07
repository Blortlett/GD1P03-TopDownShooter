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
#include "cMainMenu.h"
#include "cSharedUtils.h"


cMainMenu::cMainMenu(sf::RenderWindow& renderWindow, cGameStateManager& _GameStateManager)
	: mTitleText(cSharedUtils::GetInstance().mTitleFont, "HOTLINE", 8U)
	, mSubTitleText(cSharedUtils::GetInstance().mSubTitleFont, "MIAMI", 6U)
	, mRenderWindow(renderWindow)
	// Play Button
	, mPlayButtonUI(
		mPlayButtonPosition,
		mButtonSize,
		_GameStateManager
	)
{
	// Set Title Text
	mTitleText.setFillColor(sf::Color::Black);
	mTitleText.setCharacterSize(300);
	mTitleText.setPosition(mTitlePosition);
	mTitleText.setOrigin(mTitleText.getGlobalBounds().size / 2.0f);

	// Set SubTitle Text
	mSubTitleText.setFillColor(sf::Color::Black);
	mTitleText.setCharacterSize(300);
	mTitleText.setPosition(mTitlePosition);
	mTitleText.setOrigin(mTitleText.getGlobalBounds().size / 2.0f);
}

cMainMenu::~cMainMenu()
{

}

void cMainMenu::Update()
{
	mRenderWindow.draw(mTitleText);
	mRenderWindow.draw(mSubTitleText);
	mPlayButtonUI.Update(mRenderWindow);
	mPlayButtonUI.Draw(mRenderWindow);
}

