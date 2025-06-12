/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cExitZoneDrawTool]
Description : [This class allows dev to draw a cExitZone object to level data]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cBaseDrawTool.h"
#include "cExitTrigger.h"

class cExitZoneDrawTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(96, 50);

public:
	cExitZoneDrawTool(cLevelManager& _LevelManager);
	~cExitZoneDrawTool() {}

	// Editor useables
	void CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};