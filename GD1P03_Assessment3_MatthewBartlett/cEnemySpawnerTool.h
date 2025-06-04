#pragma once
#include "cBaseDrawTool.h"

class cEnemySpawnerTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(32, 32);

public:
	cEnemySpawnerTool(cLevelManager& _LevelManager);
	~cEnemySpawnerTool() {}

	// Editor useables
	void CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};