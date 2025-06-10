/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cOptionsMenuUI]
Description : [cOptionsMenuUI encapsulates the options UI to provide in game options to player]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cOptionsMenuUI.h"
#include "cGameSettings.h"
#include "cSharedUtils.h"

cOptionsMenuUI::cOptionsMenuUI(sf::RenderWindow& window)
	: mMenuTitleText(cSharedUtils::GetInstance().mTitleFont, "OPTIONS", 7U)
	, mWindow(window)
	, mMuteSFXButton({ mMidScreenPosX, 400.f }, { 320.f, 80.f }, *this)
	, mMuteMusicButton({ mMidScreenPosX, 510.f }, { 320.f, 80.f }, *this)
	, mVSyncButton({ mMidScreenPosX, 620.f }, { 320.f, 80.f }, *this)
	, mBackButton({ mMidScreenPosX, 730.f }, { 320.f, 80.f }, *this)
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
	mMenuBackground.setFillColor(sf::Color(11, 11, 11, 178));
}

void cOptionsMenuUI::Update()
{
	// If options menu not open: return early! dont run function at all
	if (!cGameSettings::GetInstance().GetIsOptionsMenuOpen()) return;
	
	// Press Escape to exit options menu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		cGameSettings::GetInstance().ToggleOptionsMenu(false);
	}


	// Draw Menu background
	mWindow.draw(mMenuBackground);
	mWindow.draw(mMenuTitleText);

	// Draw&Update Menu Buttons
	mMuteSFXButton.Update(mWindow);
	mMuteSFXButton.Draw(mWindow);

	mMuteMusicButton.Update(mWindow);
	mMuteMusicButton.Draw(mWindow);

	mVSyncButton.Update(mWindow);
	mVSyncButton.Draw(mWindow);

	mBackButton.Update(mWindow);
	mBackButton.Draw(mWindow);
}

void cOptionsMenuUI::ToggleVsync()
{
	mIsVsyncEnabled = !mIsVsyncEnabled;
	mWindow.setVerticalSyncEnabled(mIsVsyncEnabled);
}
