/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerSpawnerTool]
Description : [This class allows dev to draw a cPlayerSpawner object to level data]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cBaseDrawTool.h"

class cPlayerSpawnerTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(32, 32);

public:
	cPlayerSpawnerTool(cLevelManager& _LevelManager);
	~cPlayerSpawnerTool() {}

	// Editor useables
	void CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};