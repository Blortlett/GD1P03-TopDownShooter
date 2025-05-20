#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cPlayerUtils
{
private:
	cPlayerUtils();
	~cPlayerUtils();

	sf::Texture mPlayerIdleSheetTex;

public:
	sf::Sprite mPlayerIdleSheet;











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