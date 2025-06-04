#pragma once
#include "cBaseLevel.h"

class cLevel3 : public cBaseLevel
{
private:
	std::string LevelName = "Level3";

public:
	cLevel3(sf::RenderWindow& _Window);
	~cLevel3();

	void LoadLevelByName(cFileInterface& _FileInterface) override;
};