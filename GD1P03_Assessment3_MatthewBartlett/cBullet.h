#pragma once
#include "cSharedUtils.h"
#include "cBoxCollider.h"
#include "cDebugWidget.h"
#include "cGameSettings.h"

class cEnemyCharacter;
class cPlayerCharacter;


class cBullet
{
private:
	// Sprite
	sf::Sprite mBulletSprite;

	// Collider vars
	cBoxCollider mCollider;
	cDebugWidget mDebugWidget;

	// Move variables
	sf::Vector2f mPosition;
	sf::Vector2f mMoveDirection;
	float const BULLET_MOVESPEED = 500.f;

	// Active Timer
	float const mBulletActiveMaxTime = 3.f;
	float mBulletActiveTimer = mBulletActiveMaxTime;
	
	// Bullet will not draw/update unless this is true
	bool mIsActive = false;
public:
	cBullet();
	~cBullet() {}


	// Fire bullet functions
	void Fire(sf::Vector2f _StartPosition, sf::Vector2f _ShootTrajectory);
	void Fire(sf::Vector2f _StartPosition, sf::Angle _ShootAngle);
	void Move(float _DeltaTime);
	void Update(sf::RenderWindow& _Window, float _DeltaTime);
	void Draw(sf::RenderWindow& _Window);

	// Hit Function
	bool CheckCollisionWithEnemy(cEnemyCharacter& _Character, sf::Vector2f& _CollisionDirection);
	bool CheckCollisionWithPlayer(cPlayerCharacter& _Character, sf::Vector2f& _CollisionDirection);

	// Get collider
	cBoxCollider& GetCollider() { return mCollider; }

	// Disable bullet on collision
	void DisableBullet();

	// Check if bullet is active
	bool GetIsActive() { return mIsActive; }
};