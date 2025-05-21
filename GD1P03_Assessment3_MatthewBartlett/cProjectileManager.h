#pragma once
#include "cBullet.h"

class cProjectileManager
{
private:
	std::array<cBullet, 15> mPlayerBulletList;

public:
	// Constructor n dat
	cProjectileManager();
	~cProjectileManager() {}

	// Updater
	void Update(float _DeltaTime);
};