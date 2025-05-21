#include "cPlayerUtils.h"

cPlayerUtils::cPlayerUtils()
{
	mPlayerIdleSheetTex = new sf::Texture();
	if (!mPlayerIdleSheetTex->loadFromFile("Assets/SpritePack/Player/Idle/player_idle_pistol_Sheet.png"))
	{
		std::cout << "Failed to load player_idle_pistol_Sheet.png";
	}
}

cPlayerUtils::~cPlayerUtils()
{
	delete mPlayerIdleSheetTex;
}
