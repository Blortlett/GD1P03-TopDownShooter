/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerCharacter]
Description : [This class functions as the player controller]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include "cPlayerInput.h"
#include "cPlayerAnimator.h"
#include "cPlayerUtils.h"
#include "cSharedUtils.h"
#include <algorithm>
#include <cmath>


class cPlayerCharacter
{
private:
	// Input stuff
	void HandleInput();
	cPlayerInput mPlayerInput;
	sf::Vector2f mPlayerInputNormalized;

	// Rotation Stuff
	void Rotate(sf::RenderWindow& _window);
	// Movement stuff
	void Move(float _DeltaSeconds);
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;

	// Shooting
	void Shoot();


	// Constant Movement Values
	const float PLAYER_ACCELERATION = 300.f;
	const float PLAYER_MAX_VELOCITY = 200.f;
	const float PLAYER_FRICTION = .005f;

	// Animators
	cPlayerAnimator mPlayerUpperBodyAnimator;

	// Debug Stuff
	sf::RectangleShape mDebugRect;

public:
	cPlayerCharacter();
	~cPlayerCharacter() {}
	// Draw / Update
	void Update(sf::RenderWindow& _window, float _DeltaSeconds);
	void Draw(sf::RenderWindow& _window);

};