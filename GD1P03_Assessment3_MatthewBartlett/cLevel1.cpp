/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cLevel1]
Description : [This class holds level 1 runtime data]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

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
