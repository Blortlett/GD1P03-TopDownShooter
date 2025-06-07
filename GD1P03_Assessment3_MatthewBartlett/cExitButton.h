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
#pragma once
#include "cButtonUI.h"

class cExitButton : public cButtonUI
{
public:
	cExitButton(sf::Vector2f position, sf::Vector2f size, sf::RenderWindow& _RenderWindow);
	~cExitButton() = default;
	void OnButtonClick() override;
	void Draw(sf::RenderWindow& window) override;
private:
	sf::RenderWindow& mRenderWindow;
	sf::Font& mBodyFont;
	sf::Text mText;
};