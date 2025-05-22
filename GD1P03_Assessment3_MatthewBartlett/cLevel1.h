#pragma once
#include "cBaseLevel.h"

class cLevel1 : public cBaseLevel
{
private:
	sf::Texture mBackgroundTex;
	sf::Sprite* mBackgroundSprite;

public:
	cLevel1(sf::RenderWindow& _Window);
	~cLevel1();

	void Draw() override;
};