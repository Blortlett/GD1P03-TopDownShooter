#include "cBullet.h"

cBullet::cBullet()
	: mBulletSprite(cSharedUtils::GetInstance().mBulletTex)
	, mCollider(sf::FloatRect({0,0}, {16, 16}))
	, mDebugWidget(mCollider)
{
	mBulletSprite.setOrigin(mBulletSprite.getLocalBounds().size / 2.f);
}

void cBullet::Fire(sf::Vector2f _StartPosition, sf::Vector2f _ShootTrajectory)
{
	mPosition = _StartPosition;
	mCollider.MoveColliderPosition(mPosition);
	mIsActive = true;
	mMoveDirection = _ShootTrajectory;
}

void cBullet::Move(float _DeltaTime)
{
	mPosition += mMoveDirection * BULLET_MOVESPEED * _DeltaTime; // Move position
	mCollider.MoveColliderPosition(mPosition);
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
	// draw sprite
	_Window.draw(mBulletSprite);
	// If debug mode draw widget
	if (cGameSettings::GetInstance().IsDebugActive())
		mDebugWidget.DrawWidget(_Window);
}

bool cBullet::CheckCollisionWithEnemy(cEnemyCharacter& _Character, sf::Vector2f& _CollisionDirection)
{
	// Check bullet collision with enemy
	if (mCollider.CheckCollision(_Character.GetCollider(), _CollisionDirection, 1.0f))
	{
		// If collision, tell enemy object:
		_Character.OnCollision(_CollisionDirection);
	}
}
