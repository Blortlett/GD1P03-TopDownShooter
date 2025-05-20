#include "cPlayerUtils.h"

cPlayerUtils::cPlayerUtils()
	: mPlayerIdleSheet(mPlayerIdleSheetTex)
{
	mPlayerIdleSheetTex.loadFromFile("Assets/Sprites/LevelBlocks/LevelExitClosed.png");
	mPlayerIdleSheet.setTexture(mPlayerIdleSheetTex);
}

cPlayerUtils::~cPlayerUtils()
{
}
