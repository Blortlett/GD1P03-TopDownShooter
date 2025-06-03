#pragma once
#include "cBaseDrawTool.h"
#include "cExitDoor.h"

class cExitDoorDrawTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(96, 30);

public:
	cExitDoorDrawTool(cLevelManager& _LevelManager);
	~cExitDoorDrawTool() {}

	// Editor useables
	void CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};