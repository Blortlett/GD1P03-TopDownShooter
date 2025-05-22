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
#include "cBoxCollider.h"

cBoxCollider::cBoxCollider(sf::FloatRect bounds)
	: mBounds(bounds)
{

}

cBoxCollider::~cBoxCollider()
{
}

// push bounds with another object
void cBoxCollider::Move(float dx, float dy)
{
	mBounds.position.x += dx;
	mBounds.position.y += dy;
}

void cBoxCollider::MoveColliderPosition(sf::Vector2f position)
{
	mBounds.position = position;
}

bool cBoxCollider::CheckCollision(cBoxCollider& other, sf::Vector2f& direction, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{

		push = std::min(std::max(push, 0.0f), 1.0f);    // cool clamp

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f) {
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else {
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else
		{
			if (deltaY > 0.0f) {
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else {
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}
		return true;
	}
	return false;
}

bool cBoxCollider::CheckCollisionPoint(sf::Vector2f pointCollision)
{
	// Get the collider's bounds
	float left = mBounds.position.x;
	float right = mBounds.position.x + mBounds.size.x;
	float top = mBounds.position.y;
	float bottom = mBounds.position.y + mBounds.size.y;

	// Check if the point is within the bounds
	return (pointCollision.x >= left && pointCollision.x <= right &&
		pointCollision.y >= top && pointCollision.y <= bottom);
}
