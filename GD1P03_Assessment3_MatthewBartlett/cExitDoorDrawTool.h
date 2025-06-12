/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cExitDoorDrawTool]
Description : [This class allows dev to draw a cExitDoor object to level data]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cBaseDrawTool.h"
#include "cExitDoor.h"

class cExitDoorDrawTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(96, 30);

public:
	cExitDoorDrawTool(cLevelManager& _LevelManager);
	~cExitDoorDrawTool() {}

	// Editor useables
	void CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};