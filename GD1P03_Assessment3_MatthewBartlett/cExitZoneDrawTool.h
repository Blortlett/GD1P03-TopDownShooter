#pragma once
#include "cBaseDrawTool.h"
#include "cExitTrigger.h"

class cExitZoneDrawTool : public cBaseDrawTool
{
private:
	sf::Vector2f mRectSize = sf::Vector2f(96, 50);

public:
	cExitZoneDrawTool(cLevelManager& _LevelManager);
	~cExitZoneDrawTool() {}

	// Editor useables
	void CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
};