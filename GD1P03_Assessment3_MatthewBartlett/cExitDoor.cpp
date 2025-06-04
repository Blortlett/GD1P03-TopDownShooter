#include "cExitDoor.h"
#include "cSharedUtils.h"

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
	// Return from function if level not complete or door fully open
	if (mIsDoorOpenFull || !mIsDoorOpening) return;
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
	mDoorSprite.setPosition(newDoorPosition);
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
