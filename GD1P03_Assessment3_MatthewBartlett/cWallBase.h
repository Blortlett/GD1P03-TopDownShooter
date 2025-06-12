/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cWallBase]
Description : [This class can be extended to create new wall object, or collidable that player/enemies/bullets cannot move through]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cBoxCollider.h"
#include "cDebugWidget.h"
#include "cPlayerCharacter.h"

class cWallBase
{
protected:
	cBoxCollider mCollider;
	cDebugWidget mDebugWidget;
public:
	cWallBase(sf::FloatRect _Bounds, sf::Color _Color);
	~cWallBase() {}

	// Check collision with player
	void CheckCollideWithPlayer(cCharacter& character, sf::Vector2f& collisionDirection);

	// Check collide with point (used for delete wall)
	bool CheckCollideWithPoint(sf::Vector2f point);

	// DebugDraw
	void DebugDraw(sf::RenderWindow& _Window);

	// Getters
	sf::FloatRect GetBounds();
	cBoxCollider& GetCollider() { return mCollider; }
};