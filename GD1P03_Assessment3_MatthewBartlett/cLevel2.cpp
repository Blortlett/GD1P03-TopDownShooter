#include "cLevel2.h"
#include "cFileInterface.h"

cLevel2::cLevel2(sf::RenderWindow& _Window)
	: cBaseLevel(_Window, "assets/Levels/Level2.png")
{
}

cLevel2::~cLevel2()
{
}

void cLevel2::LoadLevelByName(cFileInterface& _FileInterface)
{
	_FileInterface.LoadLevelByName(this, LevelName);
	mLevelLoaded = true;
}