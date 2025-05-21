#include "cBullet.h"

cBullet::cBullet()
	: mBulletSprite(cSharedUtils::GetInstance().mBulletTex)
{
	mBulletSprite.setOrigin(mBulletSprite.getLocalBounds().size / 2.f);
}


void cBullet::Fire(sf::Vector2f _StartPosition, sf::Vector2f _ShootTrajectory)
{
	mPosition = _StartPosition;
	mIsActive = true;
	mMoveDirection = _ShootTrajectory;
}

void cBullet::Move(float _DeltaTime)
{
	mPosition += mMoveDirection * BULLET_MOVESPEED * _DeltaTime; // Move position
	mBulletSprite.setPosition(mPosition); // Set sprite to position
}

void cBullet::Update(sf::RenderWindow& _Window, float _DeltaTime)
{
	if (!mIsActive) return; // If not active GTFOutta here

	// Move bullet
	Move(_DeltaTime);
	// Draw Bullet to screen
	Draw(_Window);

	// Countdown timer until turn bullet off
	mBulletActiveTimer -= _DeltaTime;
	if (mBulletActiveTimer < 0.f)
	{
		mIsActive = false;
	}
}

void cBullet::Draw(sf::RenderWindow& _Window)
{
	_Window.draw(mBulletSprite);
}
