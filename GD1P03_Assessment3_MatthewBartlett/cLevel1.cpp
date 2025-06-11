#include "cLevel1.h"
#include "cFileInterface.h"

cLevel1::cLevel1(sf::RenderWindow& _Window)
	: cBaseLevel(_Window, "assets/Levels/Level1.png")
{}

cLevel1::~cLevel1()
{
}

void cLevel1::LoadLevelByName(cFileInterface& _FileInterface)
{
	_FileInterface.LoadLevelByName(this, LevelName);
	mLevelLoaded = true;
}
