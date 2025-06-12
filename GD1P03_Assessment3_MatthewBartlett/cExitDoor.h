/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cExitDoor]
Description : [This class can be placed in level to block characters moving through. Blocks the player exiting level until it is complete]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cWallBase.h"

class cExitDoor : public cWallBase
{
private:
	sf::Sprite mDoorSprite;

	// How far the door should open (to the left)
	float const mOpenSpeedModifier = 30.f;

public:
	cExitDoor(sf::Vector2f _StartPosition);
	~cExitDoor() {}

	// Set IsDoorOpenFull to true when finished opening
	float mDoorOpenAmount = 84.f;
	bool mIsDoorOpenFull = false;

	// Set position
	void SetPosition(sf::Vector2f _Position) { mCollider.MoveColliderPosition(_Position); }

	// I guess we gotta call something every frame
	void Update(float _DeltaTime);
	void Draw(sf::RenderWindow& _Window);

	// getters
	sf::Vector2f GetPosition();
};