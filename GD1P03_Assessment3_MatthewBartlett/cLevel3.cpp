#include "cLevel3.h"
#include "cFileInterface.h"

cLevel3::cLevel3(sf::RenderWindow& _Window)
	: cBaseLevel(_Window, "assets/Levels/Level3.png")
{
}

cLevel3::~cLevel3()
{
}

void cLevel3::LoadLevelByName(cFileInterface& _FileInterface)
{
	_FileInterface.LoadLevelByName(this, LevelName);
}