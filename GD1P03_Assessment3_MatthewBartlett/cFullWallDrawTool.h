/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cFullWallDrawTool]
Description : [This class allows dev to draw a cFullWall object to level data]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cBaseDrawTool.h"

class cLevelManager;

class cFullWallDrawTool : public cBaseDrawTool
{
public:
	cFullWallDrawTool(cLevelManager& _LevelManager);
	~cFullWallDrawTool() {}

	// Editor usables
	void CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
private:
	sf::Vector2f mRectSize = sf::Vector2f(24, 24);
};