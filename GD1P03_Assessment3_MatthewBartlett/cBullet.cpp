#include "cBullet.h"

cBullet::cBullet()
	: mBulletSprite(cSharedUtils::GetInstance().mBulletSprite)
{
}


void cBullet::Fire(sf::Vector2f _FirePosition, sf::Vector2f _AimPosition)
{
	mPosition = _FirePosition; // Set position to fire point
	mMoveDirection = _AimPosition - _FirePosition; // Calculate aimed direction
	cSharedUtils::NormalizeVector(mMoveDirection); // normalize direction
}

void cBullet::Move(float _DeltaTime)
{
	mPosition = mMoveDirection * BULLET_MOVESPEED * _DeltaTime; // Move position
	mBulletSprite.setPosition(mPosition); // Set sprite to position
}

void cBullet::Update(sf::RenderWindow& _Window, float _DeltaTime)
{
	Move(_DeltaTime);
	Draw(_Window);
}

