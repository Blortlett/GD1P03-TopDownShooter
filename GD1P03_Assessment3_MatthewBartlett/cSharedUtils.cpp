#include "cSharedUtils.h"
#include <iostream>

cSharedUtils::cSharedUtils()
{
	// Load projectile texture
	if (!mBulletTex.loadFromFile("Assets/SpritePack/Projectiles/bullet.png"))
	{
		std::cout << "Failed to load player_idle_pistol_Sheet.png";
	}
	// Load Pistol Texture
	if (!mBulletTex.loadFromFile("Assets/SpritePack/Weapon/Pistol.png"))
	{
		std::cout << "Failed to load Pistol.png";
	}
}
