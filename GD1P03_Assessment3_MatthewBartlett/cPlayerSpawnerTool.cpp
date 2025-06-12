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

#include "cPlayerSpawnerTool.h"
#include "cPlayerSpawner.h"
#include "cLevelManager.h"

cPlayerSpawnerTool::cPlayerSpawnerTool(cLevelManager& _LevelManager)
	: cBaseDrawTool(_LevelManager)
{
	mRectShape.setFillColor(sf::Color::Transparent);
	mRectShape.setOutlineColor(sf::Color::Cyan);
	mRectShape.setOutlineThickness(.5f);
	mRectShape.setSize(mRectSize);
	mRectShape.setOrigin(mRectSize / 2.f);
}

void cPlayerSpawnerTool::CompleteUseTool()
{
	// calculate new position to pass into collider bounds
	sf::Vector2f newSpawnerPosition = mRectShape.getPosition();
	// Collider is changing position and I now see why, most likely due to outline
	newSpawnerPosition.x -= .5f;
	newSpawnerPosition.y -= .5f;

	// Create cBoxCollider
	cPlayerSpawner* newPlayerSpawner = new cPlayerSpawner(newSpawnerPosition);

	// provide mLevelManager with new Collider
	mLevelManager.AddPlayerSpawner(newPlayerSpawner);
}

void cPlayerSpawnerTool::UseTool(sf::Vector2f& mousePos)
{
	// Dont need to resize nothing
}
