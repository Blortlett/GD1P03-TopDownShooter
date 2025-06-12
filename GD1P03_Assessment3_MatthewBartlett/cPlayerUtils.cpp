/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerUtils]
Description : [this singleton class loads character textures]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cPlayerUtils.h"

cPlayerUtils::cPlayerUtils()
{
	// -= Player Sprite Sheets =-
	// Load Player pistol idle animation sheet
	mPlayerIdleSheetTex = new sf::Texture();
	if (!mPlayerIdleSheetTex->loadFromFile("Assets/SpritePack/Player/Idle/player_idle_pistol_Sheet.png"))
	{
		std::cout << "Failed to load player_idle_pistol_Sheet.png" << std::endl;
	}
	// Load Player pistol shoot animation sheet
	mPlayerShootSheetTex = new sf::Texture();
	if (!mPlayerShootSheetTex->loadFromFile("Assets/SpritePack/Player/Shoot/player_shoot_pistol_Sheet.png"))
	{
		std::cout << "Failed to load player_shoot_pistol_Sheet.png" << std::endl;
	}
	// Load Player Legs idle animation sheet
	mPlayerLegsIdleTex = new sf::Texture();
	if (!mPlayerLegsIdleTex->loadFromFile("Assets/SpritePack/Legs/Player/player_legs_idle_Sheet.png"))
	{
		std::cout << "Failed to load player_legs_idle_Sheet.png" << std::endl;
	}
	// Load Player Legs Run animation sheet
	mPlayerLegsRunTex = new sf::Texture();
	if (!mPlayerLegsRunTex->loadFromFile("Assets/SpritePack/Legs/Player/player_legs_run_Sheet.png"))
	{
		std::cout << "Failed to load player_legs_run_Sheet.png" << std::endl;
	}
	// Load player death animation sheet
	mPlayerDeathSheetTex = new sf::Texture();
	if (!mPlayerDeathSheetTex->loadFromFile("Assets/SpritePack/Player/Death/player_death_Sheet.png"))
	{
		std::cout << "Failed to load player_death_Sheet.png" << std::endl;
	}


	// -= Enemy Sprite Sheets =-
	// Load Enemy pistol idle animation sheet
	mEnemyIdleSheetTex = new sf::Texture();
	if (!mEnemyIdleSheetTex->loadFromFile("Assets/SpritePack/NPCs/NPC_Gunman/NPC_Gunman_idle_pistol_Sheet.png"))
	{
		std::cout << "Failed to load NPC_Gunman_idle_pistol_Sheet.png" << std::endl;
	}
	// Load Enemy pistol fire animation sheet
	mEnemyShootSheetTex = new sf::Texture();
	if (!mEnemyShootSheetTex->loadFromFile("Assets/SpritePack/NPCs/NPC_Gunman/NPC_Gunman_shoot_pistol_Sheet.png"))
	{
		std::cout << "Failed to load NPC_Gunman_shoot_pistol_Sheet.png" << std::endl;
	}
	// Load Enemy death animation sheet
	mEnemyDeathSheetTex = new sf::Texture();
	if (!mEnemyDeathSheetTex->loadFromFile("Assets/SpritePack/NPCs/NPC_Gunman/NPC_Gunman_death_Sheet.png"))
	{
		std::cout << "Failed to load NPC_Gunman_death_Sheet.png" << std::endl;
	}
	// Load Enemy idle legs sheet
	mEnemyLegsIdle = new sf::Texture();
	if (!mEnemyLegsIdle->loadFromFile("Assets/SpritePack/Legs/NPC_Gunman/NPC_Gunman_legs_idle_Sheet.png"))
	{
		std::cout << "Failed to load NPC_Gunman_legs_idle_Sheet.png" << std::endl;
	}
	// Load Enemy run legs sheet
	mEnemyLegsRun = new sf::Texture();
	if (!mEnemyLegsRun->loadFromFile("Assets/SpritePack/Legs/NPC_Gunman/NPC_Gunman_legs_run_Sheet.png"))
	{
		std::cout << "Failed to load NPC_Gunman_legs_run_Sheet.png" << std::endl;
	}

}

cPlayerUtils::~cPlayerUtils()
{
	delete mPlayerIdleSheetTex;
	delete mPlayerShootSheetTex;
	delete mPlayerLegsIdleTex;
	delete mPlayerLegsRunTex;
	delete mPlayerDeathSheetTex;

	delete mEnemyDeathSheetTex;
	delete mEnemyIdleSheetTex;
	delete mEnemyLegsIdle;
	delete mEnemyLegsRun;
}
