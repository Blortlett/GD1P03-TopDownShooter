/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cRectPlatformTool]
Description : [cRectPlatformTool allows placing ground/wall platforms in a level structure]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cFullWallDrawTool.h"
#include "cBoxCollider.h"
#include "cLevelManager.h"


cFullWallDrawTool::cFullWallDrawTool(cLevelManager& _LevelManager)
	: cBaseDrawTool(_LevelManager)
{
	mRectShape.setFillColor(sf::Color::Transparent);
	mRectShape.setOutlineColor(sf::Color::Red);
	mRectShape.setOutlineThickness(.5f);
}

// Mouse Clicked Function
void cFullWallDrawTool::UseTool(sf::Vector2f& mousePos)
{
	mRectShape.setOrigin(sf::Vector2f(0, 0));
	sf::Vector2f NewShapeSize = sf::Vector2f(1, 1) + sf::Vector2f(
		mousePos.x - mRectShape.getPosition().x,
		mousePos.y - mRectShape.getPosition().y
	);
	
	// Reset tool size after use tool complete
	(mRectShape).setSize(NewShapeSize);
}

// Mouse released Function
void cFullWallDrawTool::CompleteUseTool()
{
	// bounds to pass in
	sf::FloatRect bounds;
	bounds = sf::FloatRect(
		mRectShape.getPosition() + (mRectShape.getLocalBounds().size / 2.0f),
		mRectShape.getLocalBounds().size
	);

	// Create cBoxCollider
	cBoxCollider* newCollider = new cBoxCollider(bounds);

	// reset size on complete
	mRectShape.setSize(mRectSize);

	// provide mLevelManager with new Collider
	mLevelManager.AddFullWall(newCollider);
}

