#include "cSharedUtils.h"
#include <iostream>

cSharedUtils::cSharedUtils()
{
	// Load projectile texture
	if (!mBulletTex.loadFromFile("Assets/SpritePack/Projectiles/bullet.png"))
	{
		std::cout << "Failed to load bullet.png";
	}
	// Load Pistol Texture
	if (!mPistolTex.loadFromFile("Assets/SpritePack/Weapon/Pistol.png"))
	{
		std::cout << "Failed to load Pistol.png";
	}
	// Load Door Texture
	if (!mExitDoorTex.loadFromFile("Assets/SpritePack/Objects/doorHeavy.png"))
	{
		std::cout << "Failed to load doorHeavy.png";
	}
}
