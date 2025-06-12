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

#pragma once
#include "cBaseLevel.h"

class cLevel2 : public cBaseLevel
{
private:
	std::string LevelName = "Level2";

public:
	cLevel2(sf::RenderWindow& _Window);
	~cLevel2();

	void LoadLevelByName(cFileInterface& _FileInterface) override;
};