#include "cEnemyCharacter.h"
#include "cPickupManager.h"
#include "cLevelProgressTracker.h"

cEnemyCharacter::cEnemyCharacter(sf::Vector2f _Position, cProjectileManager& _ProjectileManager, cPickupManager& _PickupManager, sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter)
	: cCharacter(_Position, _ProjectileManager, _GameWindow)
	, mPlayerReference(_PlayerCharacter)
	, mPickupManager(_PickupManager)
	, mCurrentBehavior(&mBehaviorPatrol)
	, mRaycaster(_PlayerCharacter)
{
	mCharacterAnimator = &mAnimator;
}

void cEnemyCharacter::UpdateWeapon(float _DeltaSeconds)
{
	if (mRaycaster.Cast(mPosition, mAnimator.GetRotation()))
		std::cout << "Caster found the player YOO" << std::endl;
	mRaycaster.DebugDraw(mRenderWindow);

	if (mShouldShoot && !mIsShooting)
	{
		// Cast mouse position
		sf::Vector2f PlayerPosition = mPlayerReference.GetPosition();
		mPistol.FireWeapon(mPosition, PlayerPosition); // fire weapon at mouse position
		mIsShooting = true;
	}
	mIsShooting = false;
}

void cEnemyCharacter::Update(float _DeltaSeconds)
{
	// Animate
	mAnimator.Animate(mBoxCollider.GetPosition(), _DeltaSeconds);

	// Only perform the rest of the updates if Enemy is alive
	if (!mAlive) return;

	// -= Movement =-
	// Get Enemy "Input"
	mCurrentBehavior->GetMovementDirection(mEnemyMovementNormalized, mIsEnemyWaiting, _DeltaSeconds);
	
	// If enemy not waiting, move around patrol route
	if (!mIsEnemyWaiting)
	{
		// Face towards movement direction
		Rotate(mPosition + mEnemyMovementNormalized);
		// Move Enemy
		Move(mEnemyMovementNormalized, _DeltaSeconds);
	}

	UpdateWeapon(_DeltaSeconds);
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
