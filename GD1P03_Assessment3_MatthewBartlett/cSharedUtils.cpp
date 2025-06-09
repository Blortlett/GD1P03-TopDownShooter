#include "cSharedUtils.h"
#include <iostream>

cSharedUtils::cSharedUtils()
{
	// -= Load Textures =-
	// Load UI Icon Full Bullet
	if (!mUIBulletFullTex.loadFromFile("Assets/SpritePack/Projectiles/ammo-pistol-Icon-Loaded.png"))
	{
		std::cout << "Failed to load ammo-pistol-Icon-Loaded.png";
	}
	// Load UI Icon empty bullet
	if (!mUIBulletEmptyTex.loadFromFile("Assets/SpritePack/Projectiles/ammo-pistol-Icon-Empty.png"))
	{
		std::cout << "Failed to load ammo-pistol-Icon-Empty.png";
	}

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
	// Menu Background Texture
	if (!mStarBackground.loadFromFile("Assets/SpritePack/Background/SpaceBackground.png"))
	{
		std::cout << "Failed to load doorHeavy.png";
	}

	// -= Load Fonts =-
	if (!mTitleFont.openFromFile("Assets/Fonts/Beyond.ttf"))
	{
		std::cout << "Failed to load Title Font: Beyond.ttf";
	}
	if (!mSubTitleFont.openFromFile("Assets/Fonts/PinkBeach.otf"))
	{
		std::cout << "Failed to load Title Font: PinkBeach.otf";
	}
	if (!mButtonFont.openFromFile("Assets/Fonts/WIDEAWAKE.TTF"))
	{
		std::cout << "Failed to load Title Font: WIDEAWAKE.TTF";
	}
}
