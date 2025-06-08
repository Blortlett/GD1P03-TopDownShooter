#include "cEnemyCharacter.h"
#include "cPickupManager.h"
#include "cLevelProgressTracker.h"

cEnemyCharacter::cEnemyCharacter(sf::Vector2f _Position, cProjectileManager& _ProjectileManager, cPickupManager& _PickupManager, sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter)
	: cCharacter(_Position, _ProjectileManager, _GameWindow)
	, mPlayerReference(_PlayerCharacter)
	, mPickupManager(_PickupManager)
	, mRaycaster(_PlayerCharacter)
	, mBehaviorReturnToSpawn(_Position)
{
	mCharacterAnimator = &mAnimator;
	mCurrentBehavior = &mBehaviorPatrol;
}

bool cEnemyCharacter::IsPlayerInCone(sf::Angle _AngleToPlayer, sf::Angle _EnemyAngleRad)
{
	// Normalize angles
	float angleToPlayerRad = cSharedUtils::GetInstance().NormalizeAngle(_AngleToPlayer.asRadians());
	float enemyAngleRad = cSharedUtils::GetInstance().NormalizeAngle(_EnemyAngleRad.asRadians());

	// Get the shortest angle difference
	float angleDiff = cSharedUtils::GetInstance().ShortestAngleDiff(angleToPlayerRad, enemyAngleRad);

	// Check if the absolute difference is within the cone
	return std::abs(angleDiff) <= CONE_HALF_ANGLE;
}

void cEnemyCharacter::DetectPlayer()
{
	/*
	// Get angle from enemy to player
	sf::Angle AngleToPlayer = cSharedUtils::GetInstance().GetLookTowardsAngle(mPosition, mPlayerReference.GetPosition());
	float angleToPlayerRad = AngleToPlayer.asRadians() + 1.5708; // adjusted value by 1.5708 to offset rad loop back from 6.28319 to 0 on the x axis
	// Current enemy look direction angle
	float enemyAngleRad = mAnimator.GetRotation().asRadians() + 1.5708; // adjusted value by 1.5708 to offset rad loop back from 6.28319 to 0 on the x axis
	// Calculate if player in enemy view cone
	if (angleToPlayerRad > enemyAngleRad - 0.785398 && angleToPlayerRad < enemyAngleRad + 0.785398)
	*/
	// Get angle from enemy position to player position
	sf::Angle AngleToPlayer = cSharedUtils::GetInstance().GetLookTowardsAngle(mPosition, mPlayerReference.GetPosition());

	if (IsPlayerInCone(AngleToPlayer, mAnimator.GetRotation()))
	{
		// Debug Draw Raycast line
		mRaycaster.DebugDraw(mRenderWindow);

		// Raycast to player
		if (mRaycaster.Cast(mPosition, AngleToPlayer))
		{
			// Player Detected
			std::cout << "Caster found the player" << std::endl;

			// Direction to player
			sf::Vector2f PlayerDirection = mPlayerReference.GetPosition() - mPosition;

			// Get Distance to player
			float PlayerDistance = 0.f;
			cSharedUtils::GetInstance().Magnitude(PlayerDirection, PlayerDistance);

			// If distance too far, chase player. If close, attack player.
			if (PlayerDistance < MIN_CHASE_DISTANCE)
			{
				mCurrentBehavior = &mBehaviorAttack;
				mShouldShoot = true;
			}
			else
			{
				mBehaviorChase.UpdateUnformation(PlayerDirection);
				mCurrentBehavior = &mBehaviorChase;
				mShouldShoot = false;
			}
		}
		else
		{
			mShouldShoot = false;
			// Player not detected
			// if I have time I will allow the enemy to go back to spawn and patrol again
		}
	}
}

void cEnemyCharacter::UpdateWeapon(float _DeltaSeconds)
{
	DetectPlayer();

	// Shoot logic
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
	
	// Face towards movement direction
	Rotate(mPosition + mEnemyMovementNormalized);
	
	// If enemy not waiting, let him walk around
	if (!mIsEnemyWaiting)
	{
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
