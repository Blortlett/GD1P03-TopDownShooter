#pragma once
#include "cBaseDrawTool.h"

class cPlayerSpawnerTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(32, 32);

public:
	cPlayerSpawnerTool(cLevelManager& _LevelManager);
	~cPlayerSpawnerTool() {}

	// Editor useables
	void CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};