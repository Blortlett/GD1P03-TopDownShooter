#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cPlayerUtils
{
private:
	cPlayerUtils();
	~cPlayerUtils();

public:
	// -= Player Textures =-
	// Upper body
	sf::Texture* mPlayerIdleSheetTex;
	sf::Texture* mPlayerShootSheetTex;
	// Lower body
	sf::Texture* mPlayerLegsIdleTex;
	sf::Texture* mPlayerLegsRunTex;
	// Full body
	sf::Texture* mPlayerDeathSheetTex;

	// -= Enemy Textures =-
	// Upper body
	sf::Texture* mEnemyIdleSheetTex;
	sf::Texture* mEnemyShootSheetTex;
	// Lower body
	sf::Texture* mEnemyLegsIdle;
	sf::Texture* mEnemyLegsRun;
	// Full body
	sf::Texture* mEnemyDeathSheetTex;










	// Singleton crap....
	// Get the single instance of the class
	static cPlayerUtils& GetInstance()
	{
		static cPlayerUtils instance; // Static instance created on first call
		return instance;
	}
	// Delete copy constructor and assignment operator to prevent copying
	cPlayerUtils(const cPlayerUtils&) = delete;
	cPlayerUtils& operator=(const cPlayerUtils&) = delete;
};