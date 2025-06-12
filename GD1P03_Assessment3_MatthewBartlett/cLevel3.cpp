/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevel3]
Description : [This class holds level 3 runtime data]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

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
	mLevelLoaded = true;
}