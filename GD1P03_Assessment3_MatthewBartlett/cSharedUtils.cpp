#include "cSharedUtils.h"
#include <iostream>

cSharedUtils::cSharedUtils()
{
	if (!mBulletTex.loadFromFile("Assets/SpritePack/Projectiles/bullet.png"))
	{
		std::cout << "Failed to load player_idle_pistol_Sheet.png";
	}
}
