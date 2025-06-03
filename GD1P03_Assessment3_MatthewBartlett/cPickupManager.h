#pragma once
#include "cPistolDropable.h"

class cPickupManager
{
private:
	std::vector<cPistolDropable*> mDroppedWeaponList;

public:
	cPickupManager();
	~cPickupManager();

	void Update();

};