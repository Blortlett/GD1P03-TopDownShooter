#include "cExitZoneDrawTool.h"
#include "cLevelManager.h"

cExitZoneDrawTool::cExitZoneDrawTool(cLevelManager& _LevelManager)
	: cBaseDrawTool(_LevelManager)
{
	mRectShape.setFillColor(sf::Color::Transparent);
	mRectShape.setOutlineColor(sf::Color::Green);
	mRectShape.setOutlineThickness(.5f);
	mRectShape.setSize(mRectSize);
	mRectShape.setOrigin(mRectSize / 2.f);
}

void cExitZoneDrawTool::UseTool(sf::Vector2f& mousePos)
{
	// no resizing needed, function can be blank
}

void cExitZoneDrawTool::CompleteUseTool()
{
	// calculate new position to pass into collider bounds
	sf::Vector2f newExitZonePosition = mRectShape.getPosition();
	// Collider is changing position and I now see why, most likely due to outline
	newExitZonePosition.x -= .5f;
	newExitZonePosition.y -= .5f;

	// Create cBoxCollider
	cExitTrigger* newExitZone= new cExitTrigger(newExitZonePosition);

	// provide mLevelManager with new Collider
	mLevelManager.AddExitZone(newExitZone);
}
