#pragma once
#include "cCharacter.h"
#include "cPlayerCharacter.h"
#include "cEnemyAnimator.h"
#include "cGameSettings.h"

class cEnemyCharacter : public cCharacter
{
private:
	// Calculate enemy movement direction
	float const mPatrolTimerMax = 3.f;
	float const mPatrolWaitTimerMax = 3.f;
	float mPatrolTimer = mPatrolTimerMax;
	bool mIsEnemyWaiting = false;
	sf::Vector2f mEnemyMovementNormalized = sf::Vector2f(1.f, 0.f);
	void GetMovementDirection(float _DeltaSeconds);

	// Calculate if enemy should fire weapon here
	void UpdateWeapon(float _DeltaSeconds) override;

	// Enemy Animator
	cEnemyAnimator mAnimator;

	// Reference to player object
	cPlayerCharacter& mPlayerReference;

public:
	cEnemyCharacter(sf::Vector2f _Position, cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter);
	~cEnemyCharacter() {}

	// Update
	void Update(float _DeltaSeconds) override;

	// On Bullet Collision
	void OnBulletCollision(sf::Vector2f _CollisionDirection);
};