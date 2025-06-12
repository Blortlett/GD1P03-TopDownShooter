/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cExitTrigger]
Description : [This class can can be placed in a level to let player collide with to leave level]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cExitTrigger.h"
#include "cPlayerCharacter.h"

cExitTrigger::cExitTrigger(sf::Vector2f _Position)
	: mCollider(sf::FloatRect(_Position, { 96.f, 30.f })) // Pos, Size
	, mDebugWidget(mCollider, sf::Color::Green)
{

}

bool cExitTrigger::CheckCollideWithPlayer(cPlayerCharacter& character)
{
	sf::Vector2f collisionDirection; // Dont care about this but my ugly function will

	// Check collider collision with player
	if (mCollider.CheckCollision(character.GetCollider(), collisionDirection, 0.f))
	{
		// If collision, Win level:
		return true;
	}
}

void cExitTrigger::DebugDraw(sf::RenderWindow& _Window)
{
	mDebugWidget.DrawWidget(_Window);
}

bool cExitTrigger::CheckCollideWithPoint(sf::Vector2f point)
{
	sf::Vector2f newPoint = point;
	newPoint += mCollider.GetHalfSize();
	return mCollider.CheckCollisionPoint(newPoint);
}

sf::Vector2f cExitTrigger::GetPosition()
{
	return mCollider.GetPosition();
}
