#include "cEnemySpawnerTool.h"
#include "cEnemySpawner.h"
#include "cLevelManager.h"

cEnemySpawnerTool::cEnemySpawnerTool(cLevelManager& _LevelManager)
	: cBaseDrawTool(_LevelManager)
{
	mRectShape.setFillColor(sf::Color::Transparent);
	mRectShape.setOutlineColor(sf::Color::Magenta);
	mRectShape.setOutlineThickness(.5f);
	mRectShape.setSize(mRectSize);
	mRectShape.setOrigin(mRectSize / 2.f);
}

void cEnemySpawnerTool::CompleteUseTool()
{
	// calculate new position to pass into collider bounds
	sf::Vector2f newSpawnerPosition = mRectShape.getPosition();
	// Collider is changing position and I now see why, most likely due to outline
	newSpawnerPosition.x -= .5f;
	newSpawnerPosition.y -= .5f;

	// Create cBoxCollider
	cEnemySpawner* newEnemySpawner = new cEnemySpawner(newSpawnerPosition);

	// provide mLevelManager with new Collider
	mLevelManager.AddEnemySpawner(newEnemySpawner);
	std::cout << "Added enemy spawner :)" << std::endl;
}

void cEnemySpawnerTool::UseTool(sf::Vector2f& mousePos)
{
	// Don't even think about doing anything
}
