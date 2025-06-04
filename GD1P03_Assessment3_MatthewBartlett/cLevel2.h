#pragma once
#include "cBaseLevel.h"

class cLevel2 : public cBaseLevel
{
private:
	std::string LevelName = "Level2";

public:
	cLevel2(sf::RenderWindow& _Window);
	~cLevel2();

	void LoadLevelByName(cFileInterface& _FileInterface) override;
};