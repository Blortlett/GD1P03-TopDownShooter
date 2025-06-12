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

#pragma once
#include "cBaseLevel.h"

class cLevel3 : public cBaseLevel
{
private:
	std::string LevelName = "Level3";

public:
	cLevel3(sf::RenderWindow& _Window);
	~cLevel3();

	void LoadLevelByName(cFileInterface& _FileInterface) override;
};