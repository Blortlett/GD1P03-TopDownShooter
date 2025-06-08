#pragma once
#include "cCharacter.h"
#include "cPlayerCharacter.h"
#include "cEnemyAnimator.h"
#include "cGameSettings.h"
#include "iBehavior.h"
#include "cBehaviorPatrol.h"
#include "cRaycaster.h"

class cPickupManager;

class cEnemyCharacter : public cCharacter
{
private:
	// Is enemy alive?
	bool mAlive = true;

	// Enemy movement vars
	bool mIsEnemyWaiting = false;
	sf::Vector2f mEnemyMovementNormalized = { 1.f, 0.f };
	
	// Behavior states
	cBehaviorPatrol mBehaviorPatrol;
	iBehavior* mCurrentBehavior;

	// Calculate if enemy should fire weapon here
	bool mShouldShoot = false;
	void UpdateWeapon(float _DeltaSeconds) override;

	// Enemy Raycaster
	cRaycaster mRaycaster;
	// Enemy Animator
	cEnemyAnimator mAnimator;

	// Game Manager References
	cPickupManager& mPickupManager;

	// Reference to player object
	cPlayerCharacter& mPlayerReference;

public:
	cEnemyCharacter(sf::Vector2f _Position, cProjectileManager& _ProjectileManager, cPickupManager& _PickupManager, sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter);
	~cEnemyCharacter() {}

	// Update
	void Update(float _DeltaSeconds) override;

	// On Bullet Collision
	void OnBulletCollision(sf::Vector2f _CollisionDirection);

	// Getters
	bool IsAlive() { return mAlive; }
};