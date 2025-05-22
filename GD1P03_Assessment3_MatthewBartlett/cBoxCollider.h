/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cBoxCollider]
Description : [This class should be stored as a member of any object you wish to have collisions]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cBoxCollider
{
public:
	cBoxCollider(sf::FloatRect bounds);
	~cBoxCollider();

	void Move(float dx, float dy);
	void MoveColliderPosition(sf::Vector2f position);
	bool CheckCollision(cBoxCollider& other, sf::Vector2f& direction, float push);
	bool CheckCollisionPoint(sf::Vector2f pointCollision);
	sf::FloatRect GetBounds() { return mBounds; }
	sf::Vector2f GetPosition() { return mBounds.position; }
	sf::Vector2f GetHalfSize() { return mBounds.size / 2.0f; }
	sf::FloatRect mBounds;
private:
};
