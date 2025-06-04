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
	// Dont need to resize nothing
}

void cPlayerSpawnerTool::UseTool(sf::Vector2f& mousePos)
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
