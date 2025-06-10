#pragma once
#include "cCharacter.h"
#include "cPlayerCharacter.h"
#include "cEnemyAnimator.h"
#include "cEnemyAnimatorLegs.h"
#include "cGameSettings.h"
#include "iBehavior.h"
#include "cBehaviorPatrol.h"
#include "cBehaviorAttack.h"
#include "cBehaviorChase.h"
#include "cBehaviorReturnSpawn.h"
#include "cRaycaster.h"

class cPickupManager;

class cEnemyCharacter : public cCharacter
{
private:
	// Enemy view cone
	const float CONE_HALF_ANGLE = 1.5708f; // 90 degree
	const float MIN_CHASE_DISTANCE = 250.f;

	// Enemy movement vars
	bool mIsEnemyWaiting = false;
	sf::Vector2f mEnemyMovementNormalized = { 1.f, 0.f };

	// Behavior states
	iBehavior* mCurrentBehavior;
	cBehaviorPatrol mBehaviorPatrol;
	cBehaviorAttack mBehaviorAttack;
	cBehaviorChase mBehaviorChase;
	cBehaviorReturnToSpawn mBehaviorReturnToSpawn;

	// Enemy Raycaster
	cRaycaster mRaycaster;

	// Enemy Animator
	cEnemyAnimator mAnimator;
	cEnemyAnimatorLegs mAnimatorLegs;

	// Game Manager References
	cPickupManager& mPickupManager;

	// Reference to player object
	cPlayerCharacter& mPlayerReference;

	// Is the enemy agro to player?
	bool mHasAgro = false;
	bool mIsPlayerDetected = false;

	// Time Enemy will wait before swap to returnToSpawn behavior after no enemy detection
	float const mChaseNoAgroTimerMax = 4.f;
	float mChaseNoAgroTimer;

	// Time Enemy will spend returning to spawn
	float const mReturnToSpawnTimerMax = 5.f;
	float mReturnToSpawnTimer = mReturnToSpawnTimerMax;

	// Detect player code
	bool IsPlayerInCone(sf::Angle _AngleToPlayer, sf::Angle _EnemyAngleRad);
	void DetectPlayer();

	// Calculate if enemy should fire weapon here
	void UpdateWeapon(float _DeltaSeconds) override;

public:
	cEnemyCharacter(sf::Vector2f _Position, cProjectileManager& _ProjectileManager, cPickupManager& _PickupManager, sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter);
	~cEnemyCharacter() {}

	// Update
	void Update(float _DeltaSeconds) override;

	// Enemy helpers
	void HandleAgro(float _DeltaTime);
	void HandleReturnToSpawn(float _DeltaTime);

	// Respawn logic
	void RespawnEnemy();

	// Enemy hit by bullet
	void OnBulletCollision(sf::Vector2f _CollisionDirection);

	// Getters
	bool IsAlive() { return mAlive; }
};