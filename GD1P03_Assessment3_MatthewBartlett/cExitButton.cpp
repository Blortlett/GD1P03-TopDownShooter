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
#include "cExitButton.h"
#include "cSharedUtils.h"
#include "cMainMenu.h"

cExitButton::cExitButton(sf::Vector2f position, sf::Vector2f size, sf::RenderWindow& _RenderWindow)
	: cButtonUI(position, size)
	, mText(mBodyFont, "EXIT", 4U)
	, mBodyFont(cSharedUtils::GetInstance().mButtonFont)
	, mRenderWindow(_RenderWindow)
{
	// get font
	mText.setCharacterSize(60);
	mText.setFillColor(sf::Color::Black);
	// Center text
	mText.setPosition(position);
	mText.setOrigin(mText.getGlobalBounds().size / 2.0f);
}

void cExitButton::OnButtonClick()
{
	// Exit game
	mRenderWindow.close();
}

void cExitButton::Draw(sf::RenderWindow& window)
{
	cButtonUI::Draw(window);
	window.draw(mText);
}
