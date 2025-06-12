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

#include "cExitDoorDrawTool.h"
#include "cLevelManager.h"

cExitDoorDrawTool::cExitDoorDrawTool(cLevelManager& _LevelManager)
	: cBaseDrawTool(_LevelManager)
{
	mRectShape.setFillColor(sf::Color::Transparent);
	mRectShape.setOutlineColor(sf::Color::Blue);
	mRectShape.setOutlineThickness(.5f);
	mRectShape.setSize(mRectSize);
	mRectShape.setOrigin(mRectSize / 2.f);
}

void cExitDoorDrawTool::UseTool(sf::Vector2f& mousePos)
{
	
}

void cExitDoorDrawTool::CompleteUseTool()
{
	// calculate new position to pass into collider bounds
	sf::Vector2f newExitPosition = mRectShape.getPosition();
	// Collider is changing position and I now see why, most likely due to outline
	newExitPosition.x -= .5f;
	newExitPosition.y -= .5f;

	// Create cBoxCollider
	cExitDoor* newExitDoor = new cExitDoor(newExitPosition);

	// provide mLevelManager with new Collider
	mLevelManager.AddExitDoor(newExitDoor);
}
