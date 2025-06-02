#include "cEnemyCharacter.h"

cEnemyCharacter::cEnemyCharacter(sf::Vector2f _Position, cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter)
	: cCharacter(_Position, _ProjectileManager, _GameWindow)
	, mPlayerReference(_PlayerCharacter)
{
	mCharacterAnimator = &mAnimator;
}

void cEnemyCharacter::GetMovementDirection(float _DeltaSeconds)
{
	// coutdown
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

	// Animate
	mAnimator.Animate(mPlayerReference.GetPosition(), _DeltaSeconds);
}
