#pragma once
#include "cSharedUtils.h"

class cBullet
{
private:
	// Sprite
	sf::Sprite mBulletSprite;

	// Move variables
	sf::Vector2f mPosition;
	sf::Vector2f mMoveDirection;
	float const BULLET_MOVESPEED = 250.f;

	// Active Timer
	float const mBulletActiveMaxTime = 3.f;
	float mBulletActiveTimer = mBulletActiveMaxTime;

	// Debug
	
public:
	cBullet();
	~cBullet() {}

	bool mIsActive = false;

	void Fire(sf::Vector2f _StartPosition, sf::Vector2f _ShootTrajectory);
	void Move(float _DeltaTime);
	void Update(sf::RenderWindow& _Window, float _DeltaTime);
	void Draw(sf::RenderWindow& _Window);
};