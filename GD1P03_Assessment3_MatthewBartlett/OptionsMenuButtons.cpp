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
#include "OptionsMenuButtons.h"
#include "cSharedUtils.h"
#include "cOptionsMenuUI.h"
#include "cAudioManager.h"
#include "cGameSettings.h"


//	-= Toggle Mute In Game SFX =-
cMuteSFX::cMuteSFX(sf::Vector2f position, sf::Vector2f size, cOptionsMenuUI& _OptionsMenu)
	: cButtonUI(position, size)
	, mText(mBodyFont, "MUTE SFX", 8U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mOptionsMenu(_OptionsMenu)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cMuteSFX::OnButtonClick()
{
	// Mute SFX
	cAudioManager::GetInstance().MuteSFX();
}

void cMuteSFX::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}



//	-= Toggle Mute In Game Music =-
cMuteMusic::cMuteMusic(sf::Vector2f position, sf::Vector2f size, cOptionsMenuUI& _OptionsMenu)
	: cButtonUI(position, size)
	, mText(mBodyFont, "MUTE MUSIC", 10U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mOptionsMenu(_OptionsMenu)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cMuteMusic::OnButtonClick()
{
	// Mute Music
	cAudioManager::GetInstance().MuteMusic();
}

void cMuteMusic::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}



//	-= Toggle VSync Button =-
cVSyncButton::cVSyncButton(sf::Vector2f position, sf::Vector2f size, cOptionsMenuUI& _OptionsMenu)
	: cButtonUI(position, size)
	, mText(mBodyFont, "VSYNC", 5U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mOptionsMenu(_OptionsMenu)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cVSyncButton::OnButtonClick()
{
	// Enable VSync
	mOptionsMenu.ToggleVsync();
}

void cVSyncButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}



//	-= Back to pause menu Button =-
cBackButton::cBackButton(sf::Vector2f position, sf::Vector2f size, cOptionsMenuUI& _OptionsMenu)
	: cButtonUI(position, size)
	, mText(mBodyFont, "BACK", 4U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mOptionsMenu(_OptionsMenu)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cBackButton::OnButtonClick()
{
	// Return to pause menu
	cGameSettings::GetInstance().ToggleOptionsMenu(false);
}

void cBackButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}