#include "cLevel1.h"

cLevel1::cLevel1(sf::RenderWindow& _Window)
	: cBaseLevel(_Window)
{
	if (!mBackgroundTex.loadFromFile("assets/Levels/Level1.png"))
	{
		std::cout << "Failed to load Level1.png";
	}

	mBackgroundSprite = new sf::Sprite(mBackgroundTex);
	mBackgroundSprite->setOrigin(mBackgroundSprite->getLocalBounds().size / 2.f);
}

cLevel1::~cLevel1()
{
	delete mBackgroundSprite;
}

void cLevel1::Draw()
{
	mRenderWindow.draw(*mBackgroundSprite);
	DebugDraw();
}
