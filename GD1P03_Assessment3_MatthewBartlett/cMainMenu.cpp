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
	: mTitleText(cSharedUtils::GetInstance().mTitleFont, "STARLINE", 8U)
	, mSubTitleText(cSharedUtils::GetInstance().mSubTitleFont, "MIAMI", 6U)
	, mRenderWindow(renderWindow)
	, mPlayButtonUI(mPlayButtonPosition, mButtonSize, *this)
	, mExitButtonUI(mPlayButtonPosition + sf::Vector2f(0.f, 200.f), mButtonSize, renderWindow)
	, mStarBackground(cSharedUtils::GetInstance().mStarBackground)
{
	// Title Backdrop
	mTitleBackdrop.setSize({ 1710.f, 370.f });
	mTitleBackdrop.setPosition({ 683.f, 235.f });
	mTitleBackdrop.setOrigin(mTitleBackdrop.getSize() / 2.f);
	mTitleBackdrop.setFillColor(sf::Color(5, 5, 5, 150));

	// Set Title Text
	mTitleText.setFillColor(sf::Color::Magenta);
	mTitleText.setCharacterSize(280U);
	mTitleText.setPosition(mTitlePosition);
	mTitleText.setOrigin(mTitleText.getGlobalBounds().size / 2.0f);
	// Set SubTitle Text
	mSubTitleText.setFillColor(sf::Color::White);
	mSubTitleText.setCharacterSize(200U);
	mSubTitleText.setPosition(mTitlePosition + sf::Vector2f(1100.f, 200.f));
	mSubTitleText.setOrigin(mTitleText.getGlobalBounds().size / 2.0f);

	// Set background pos
	mStarBackground.setPosition({ 683.f, 500.f });
	mStarBackground.setOrigin(mStarBackground.getGlobalBounds().size / 2.f);
}

cMainMenu::~cMainMenu()
{

}

void cMainMenu::Update()
{
	// Draw Background
	mRenderWindow.draw(mStarBackground);

	// Update / Draw buttons
	mPlayButtonUI.Update(mRenderWindow);
	mExitButtonUI.Update(mRenderWindow);
	mPlayButtonUI.Draw(mRenderWindow);
	mExitButtonUI.Draw(mRenderWindow);

	// Draw Title
	mRenderWindow.draw(mTitleBackdrop);
	mRenderWindow.draw(mTitleText);
	mRenderWindow.draw(mSubTitleText);
}

