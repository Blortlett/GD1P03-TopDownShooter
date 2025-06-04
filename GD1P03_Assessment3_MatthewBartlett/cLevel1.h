#pragma once
#include "cBaseLevel.h"

class cLevel1 : public cBaseLevel
{
private:
	std::string LevelName = "Level1";

public:
	cLevel1(sf::RenderWindow& _Window);
	~cLevel1();

	void LoadLevelByName(cFileInterface& _FileInterface) override;
};