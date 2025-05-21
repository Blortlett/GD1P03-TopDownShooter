#include "cLevel1.h"

cLevel1::cLevel1()
{
	if (!mBackgroundTex.loadFromFile("assets/Levels/Level1.png"))
	{
		std::cout << "Failed to load Level1.png";
	}

	mBackgroundSprite = new sf::Sprite(mBackgroundTex);
	mBackgroundSprite->setOrigin(mBackgroundSprite->getLocalBounds().size / 2.f);
}

void cLevel1::Draw(sf::RenderWindow& _Window)
{
	
	_Window.draw(*mBackgroundSprite);
}
