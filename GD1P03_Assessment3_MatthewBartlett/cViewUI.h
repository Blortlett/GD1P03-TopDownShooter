#pragma once
#include <SFML/Graphics.hpp>
#include "cAmmoUI.h"

class cPlayerCharacter;

class cViewUI
{
private:
	sf::View mUICanvas;
	cAmmoUI mAmmoUI;

	sf::RenderWindow& mGameWindow;
	cPlayerCharacter& mPlayerCharacter;

public:
	cViewUI(sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter);

	void Update();
	void Draw();
};