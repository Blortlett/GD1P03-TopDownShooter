/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayButton]
Description : [cPlayButton provides a button for the player to push to start the game from the main menu]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cPlayButton.h"
#include "cSharedUtils.h"

cPlayButton::cPlayButton(sf::Vector2f position, sf::Vector2f size, cGameStateManager& _GameStateManager)
	: cButtonUI(position, size)
	, mText(mBodyFont, "PLAY", 6U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mGameStateManager(_GameStateManager)
{
	// get font
	mText.setString("PLAY");
	mText.setCharacterSize(20);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cPlayButton::OnButtonClick()
{
	
}

void cPlayButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}
