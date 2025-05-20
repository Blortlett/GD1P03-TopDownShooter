#include "cPlayerUtils.h"

cPlayerUtils::cPlayerUtils()
	: mPlayerIdleSheet(mPlayerIdleSheetTex)
{
	if (!mPlayerIdleSheetTex.loadFromFile("Assets/SpritePack/Player/Idle/player_idle_pistol_Sheet.png"))
	{
		std::cout << "Failed to load player_idle_pistol_Sheet.png";
	}
	mPlayerIdleSheet.setTexture(mPlayerIdleSheetTex);
}

cPlayerUtils::~cPlayerUtils()
{
}
