/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevel2]
Description : [This class holds level 2 runtime data]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

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