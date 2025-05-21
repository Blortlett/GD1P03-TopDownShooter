#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cLevel1
{
private:
	sf::Texture mBackgroundTex;
	sf::Sprite* mBackgroundSprite;

public:
	cLevel1();
	~cLevel1() {}

	void Draw(sf::RenderWindow& _Window);
};