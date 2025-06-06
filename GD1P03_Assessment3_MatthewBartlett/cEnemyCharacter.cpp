#include "cEnemyCharacter.h"
#include "cPickupManager.h"
#include "cLevelProgressTracker.h"

cEnemyCharacter::cEnemyCharacter(sf::Vector2f _Position, cProjectileManager& _ProjectileManager, cPickupManager& _PickupManager, sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter)
	: cCharacter(_Position, _ProjectileManager, _GameWindow)
	, mPlayerReference(_PlayerCharacter)
	, mPickupManager(_PickupManager)
{
	mCharacterAnimator = &mAnimator;
}

void cEnemyCharacter::GetMovementDirection(float _DeltaSeconds)
{
	// Countdown timer
	mPatrolTimer -= _DeltaSeconds;
	// On Timer loop
	if (mPatrolTimer <= 0.f)
	{
		if (mIsEnemyWaiting)
		{ // Wait timer expired, change directions
			mEnemyMovementNormalized.x *= -1;
			// Set enemy to patrolling
			mIsEnemyWaiting = false;
			// Reset timer
			mPatrolTimer = mPatrolTimerMax;
		}
		else
		{ // Patrol timer expired, get to waiting
			mIsEnemyWaiting = true;
			mPatrolTimer = mPatrolWaitTimerMax;
		}
	}
}

void cEnemyCharacter::UpdateWeapon(float _DeltaSeconds)
{
	if (!mIsShooting)
	{
		// Cast mouse position
		sf::Vector2f PlayerPosition = mPlayerReference.GetPosition();
		mPistol.FireWeapon(mPosition, PlayerPosition); // fire weapon at mouse position
		mIsShooting = true;
	}
	//if (!mPlayerInput.IsLeftClickPressed())
	mIsShooting = false;
}

void cEnemyCharacter::Update(float _DeltaSeconds)
{
	// Animate
	mAnimator.Animate(mBoxCollider.GetPosition(), _DeltaSeconds);

	if (!mAlive) return;
	// Only perform the rest of the updates if Enemy is alive

	// -= Movement =-
	// Enemy "Input"
	GetMovementDirection(_DeltaSeconds);
	// If enemy not waiting, move around patrol route
	if (!mIsEnemyWaiting)
	{
		// Face towards movement direction
		Rotate(mPosition + mEnemyMovementNormalized);
		// Move Enemy
		Move(mEnemyMovementNormalized, _DeltaSeconds);
	}
}

void cEnemyCharacter::OnBulletCollision(sf::Vector2f _CollisionDirection)
{
	// Only run entire function once
	if (!mAlive) return;

	// Kill enemy
	mAlive = false;
	// Drop weapon
	mPickupManager.CreateNewWeaponDrop(mPosition, mCharacterAnimator->GetRotation(), 12);
	// Swap current animation to death animation
	mAnimator.SwapToEnemyDeath();

	// Track enemy death
	cLevelProgressTracker::GetInstance().ReduceEnemyCount();
}
