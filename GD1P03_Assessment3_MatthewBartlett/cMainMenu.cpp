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
	, mPlayButtonUI(mPlayButtonPosition, mButtonSize, *this)
{
	// Set Title Text
	mTitleText.setFillColor(sf::Color::Magenta);
	mTitleText.setCharacterSize(300U);
	mTitleText.setPosition(mTitlePosition);
	mTitleText.setOrigin(mTitleText.getGlobalBounds().size / 2.0f);

	// Set SubTitle Text
	mSubTitleText.setFillColor(sf::Color::White);
	mTitleText.setCharacterSize(150U);
	mTitleText.setPosition(mTitlePosition + sf::Vector2f(0, 150));
	mTitleText.setOrigin(mTitleText.getGlobalBounds().size / 2.0f);
}

cMainMenu::~cMainMenu()
{

}

void cMainMenu::Update()
{
	mPlayButtonUI.Update(mRenderWindow);

	mRenderWindow.draw(mTitleText);
	mRenderWindow.draw(mSubTitleText);
	mPlayButtonUI.Draw(mRenderWindow);
}

