/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cHalfWallDrawTool]
Description : [This class allows dev to draw a cHalfWall object to level data]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/


#include "cHalfWallDrawTool.h"
#include "cHalfWall.h"
#include "cLevelManager.h"

cHalfWallDrawTool::cHalfWallDrawTool(cLevelManager& _LevelManager)
	: cBaseDrawTool(_LevelManager)
{
	sf::Color Orange(255, 165, 0);
	mRectShape.setFillColor(sf::Color::Transparent);
	mRectShape.setOutlineColor(Orange);
	mRectShape.setOutlineThickness(.5f);
}

void cHalfWallDrawTool::UseTool(sf::Vector2f& mousePos)
{
	mRectShape.setOrigin(sf::Vector2f(0, 0));
	sf::Vector2f NewShapeSize = sf::Vector2f(1, 1) + sf::Vector2f(
		mousePos.x - mRectShape.getPosition().x,
		mousePos.y - mRectShape.getPosition().y
	);

	// Reset tool size after use tool complete
	(mRectShape).setSize(NewShapeSize);
}


void cHalfWallDrawTool::CompleteUseTool()
{
	// calculate new position to pass into collider bounds
	sf::Vector2f NewColliderPosition = mRectShape.getPosition() + (mRectShape.getLocalBounds().size / 2.0f);
	// Collider is changing position and I have no idea why... hacky fix for the homies below
	NewColliderPosition.x -= .5f;
	NewColliderPosition.y -= .5f;
	// calculate new size to pass into collider bounds
	sf::Vector2f NewColliderSize = mRectShape.getGlobalBounds().size;
	// Collider is changing size and I have no idea why... hacky fix for the homies below
	NewColliderSize.x -= 1.f;
	NewColliderSize.y -= 1.f;

	// bounds to pass in to new Collider
	sf::FloatRect bounds = sf::FloatRect(NewColliderPosition, NewColliderSize);

	// Create cBoxCollider
	cHalfWall* newHalfWall = new cHalfWall(bounds);

	// reset cursor square size on complete
	mRectShape.setSize(mRectSize);

	// provide mLevelManager with new Collider
	mLevelManager.AddHalfWall(newHalfWall);
}