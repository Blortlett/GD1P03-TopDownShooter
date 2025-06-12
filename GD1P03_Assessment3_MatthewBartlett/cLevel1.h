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


#pragma once
#include "cBaseLevel.h"

class cLevel1 : public cBaseLevel
{
private:
	std::string LevelName = "Level1";

public:
	cLevel1(sf::RenderWindow& _Window);
	~cLevel1();

	void LoadLevelByName(cFileInterface& _FileInterface) override;
};