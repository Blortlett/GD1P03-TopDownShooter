#include "cPlayerUtils.h"

cPlayerUtils::cPlayerUtils()
{
	// -= Player Sprite Sheets =-
	// Load Player pistol idle animation sheet
	mPlayerIdleSheetTex = new sf::Texture();
	if (!mPlayerIdleSheetTex->loadFromFile("Assets/SpritePack/Player/Idle/player_idle_pistol_Sheet.png"))
	{
		std::cout << "Failed to load player_idle_pistol_Sheet.png";
	}


	// -= Enemy Sprite Sheets =-
	// Load Enemy pistol idle animation sheet
	mEnemyIdleSheetTex = new sf::Texture();
	if (!mEnemyIdleSheetTex->loadFromFile("Assets/SpritePack/NPCs/NPC_Gunman/NPC_Gunman_idle_pistol_Sheet.png"))
	{
		std::cout << "Failed to load NPC_Gunman_idle_pistol_Sheet.png";
	}
	// Load Enemy death animation sheet
	mEnemyDeathSheetTex = new sf::Texture();
	if (!mEnemyDeathSheetTex->loadFromFile("Assets/SpritePack/NPCs/NPC_Gunman/NPC_Gunman_death_Sheet.png"))
	{
		std::cout << "Failed to load NPC_Gunman_idle_pistol_Sheet.png";
	}
}

cPlayerUtils::~cPlayerUtils()
{
	delete mEnemyDeathSheetTex;
	delete mPlayerIdleSheetTex;
	delete mEnemyIdleSheetTex;
}
