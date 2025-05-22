/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cCameraManager]
Description : [The cCameraManager class provides functionality to the player camera / sfml view]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
//#include "cPlayerCharacter.h"
class cPlayerCharacter;

class cCameraManager
{
private:
	// Player Character reference
	cPlayerCharacter& mPlayerCharacter;
	// Game Window
	sf::RenderWindow& mRenderWindow;
	
	// Camera variables
	sf::View mView;
	sf::Vector2f mCameraViewSize;

	float mFollowSpeed = 5.f;

public:
	cCameraManager(cPlayerCharacter& _PlayerCharacter, sf::RenderWindow& _RenderWindow);
	~cCameraManager() {}

	// Update camera
	void Update(float _DeltaSeconds);

	// Getters
	sf::View& GetCameraView() { return mView; }
};