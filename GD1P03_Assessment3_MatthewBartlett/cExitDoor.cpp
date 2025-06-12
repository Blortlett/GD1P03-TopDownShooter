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

#include "cExitDoor.h"
#include "cSharedUtils.h"
#include "cLevelProgressTracker.h"

cExitDoor::cExitDoor(sf::Vector2f _StartPosition)
	: cWallBase(sf::FloatRect(_StartPosition, { 96.f, 30.f }), sf::Color::Blue)
	, mDoorSprite(cSharedUtils::GetInstance().mExitDoorTex)
{
	sf::Angle deg90 = sf::degrees(90.0f);
	mDoorSprite.setPosition(_StartPosition);
	mDoorSprite.setRotation(deg90);
	mDoorSprite.setOrigin(mDoorSprite.getLocalBounds().size / 2.f);
}

void cExitDoor::Update(float _DeltaTime)
{
	mDoorSprite.setPosition(mCollider.GetPosition());

	// Return from function if level not complete
	if (!cLevelProgressTracker::GetInstance().CheckLevelComplete())
		return;
	// Return from function if door fully open
	if (mIsDoorOpenFull)
		return;

	if (mDoorOpenAmount <= 0.f)
	{
		mIsDoorOpenFull = true;
	}

	// calc door speed each frame because jank?
	float doorSpeed = mOpenSpeedModifier * _DeltaTime;
	mDoorOpenAmount -= doorSpeed;

	// Get door pos
	sf::Vector2f doorPosition = mCollider.GetPosition();
	// Change only x value
	sf::Vector2f newDoorPosition = sf::Vector2f(doorPosition.x - doorSpeed, doorPosition.y);
	// Begin opening door
	mCollider.MoveColliderPosition(newDoorPosition);
}

void cExitDoor::Draw(sf::RenderWindow& _Window)
{
	// Draw door sprite
	_Window.draw(mDoorSprite);
}

sf::Vector2f cExitDoor::GetPosition()
{
	return mCollider.GetPosition();
}
