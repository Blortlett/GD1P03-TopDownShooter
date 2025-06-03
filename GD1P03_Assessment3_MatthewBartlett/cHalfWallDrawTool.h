#pragma once
#include "cBaseDrawTool.h"

class cLevelManager;

class cHalfWallDrawTool : public cBaseDrawTool
{
public:
	cHalfWallDrawTool(cLevelManager& _LevelManager);
	~cHalfWallDrawTool() {}

	// Editor usables
	void CompleteUseTool() override;
	void UseTool(sf::Vector2f& mousePos) override;
private:
	sf::Vector2f mRectSize = sf::Vector2f(24, 24);
};