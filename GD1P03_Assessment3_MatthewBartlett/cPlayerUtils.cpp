#include "cPlayerUtils.h"

cPlayerUtils::cPlayerUtils()
{
	// Load Player pistol idle
	mPlayerIdleSheetTex = new sf::Texture();
	if (!mPlayerIdleSheetTex->loadFromFile("Assets/SpritePack/Player/Idle/player_idle_pistol_Sheet.png"))
	{
		std::cout << "Failed to load player_idle_pistol_Sheet.png";
	}

	// Load Enemy pistol idle
	mEnemyIdleSheetTex = new sf::Texture();
	if (!mEnemyIdleSheetTex->loadFromFile("Assets/SpritePack/NPCs/NPC_Gunman/NPC_Gunman_idle_pistol_Sheet.png"))
	{
		std::cout << "Failed to load NPC_Gunman_idle_pistol_Sheet.png";
	}
}

cPlayerUtils::~cPlayerUtils()
{
	delete mPlayerIdleSheetTex;
}
