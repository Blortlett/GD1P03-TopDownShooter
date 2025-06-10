#include "cEnemyCharacter.h"
#include "cPickupManager.h"
#include "cLevelProgressTracker.h"

cEnemyCharacter::cEnemyCharacter(sf::Vector2f _Position, cProjectileManager& _ProjectileManager, cPickupManager& _PickupManager, sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter)
	: cCharacter(_Position, _ProjectileManager, _GameWindow, false)
	, mPlayerReference(_PlayerCharacter)
	, mPickupManager(_PickupManager)
	, mRaycaster(_PlayerCharacter)
	, mBehaviorReturnToSpawn(_Position)
{
	mCharacterAnimator = &mAnimator;
	mCharacterAnimatorBottom = &mAnimatorLegs;
	mCurrentBehavior = &mBehaviorPatrol;

	// -= CONE DEBUG SHAPES =-
	mDebugConeLeft.setFillColor(sf::Color(255, 0, 0, 50));  // Semi-transparent red
	mDebugConeLeft.setSize({ 200.f, 2.f });
	mDebugConeLeft.setOrigin({ 0.f, 1.f });

	mDebugConeRight.setFillColor(sf::Color(255, 0, 0, 50));
	mDebugConeRight.setSize({ 200.f, 2.f });
	mDebugConeRight.setOrigin({ 0.f, 1.f });
	// -= CONE DEBUG SHAPES =-
}

bool cEnemyCharacter::IsPlayerInCone(sf::Angle _AngleToPlayer, sf::Angle _EnemyAngleRad)
{
	// Normalize both angles to [0, 2pi]
	float playerAngle = cSharedUtils::GetInstance().NormalizeAngle(_AngleToPlayer.asRadians());
	float enemyAngle = cSharedUtils::GetInstance().NormalizeAngle(_EnemyAngleRad.asRadians());

	// Calculate the relative angle from enemy's facing direction to player
	float relativeAngle = playerAngle - enemyAngle;

	// Normalize the relative angle to [-pi, pi]
	const float PI = 3.14159265359f;
	while (relativeAngle > PI) relativeAngle -= 2.0f * PI;
	while (relativeAngle < -PI) relativeAngle += 2.0f * PI;

	// Check if the relative angle is within the cone
	return std::abs(relativeAngle) <= CONE_HALF_ANGLE;
}

void cEnemyCharacter::DetectPlayer()
{
	// Get angle from enemy position to player position
	sf::Angle AngleToPlayer = cSharedUtils::GetInstance().GetLookTowardsAngle(mPosition, mPlayerReference.GetPosition());

	// -= CONE DEBUG SHAPES =-
	sf::Angle enemyAngle = mAnimator.GetRotation();
	mDebugConeLeft.setPosition(mPosition);
	mDebugConeLeft.setRotation(enemyAngle - sf::radians(CONE_HALF_ANGLE));
	mRenderWindow.draw(mDebugConeLeft);

	mDebugConeRight.setPosition(mPosition);
	mDebugConeRight.setRotation(enemyAngle + sf::radians(CONE_HALF_ANGLE));
	mRenderWindow.draw(mDebugConeRight);
	// -= CONE DEBUG SHAPES =-

	if (IsPlayerInCone(AngleToPlayer, mAnimator.GetRotation()))
	{
		// Debug Draw Raycast line
		mRaycaster.DebugDraw(mRenderWindow);
		std::cout << "Player Position: " << mPlayerReference.GetPosition().x << ", " << mPlayerReference.GetPosition().y << std::endl;

		// Raycast to player
		if (mRaycaster.Cast(mPosition, AngleToPlayer))
		{
			// Player hit by ray
			// Direction to player
			sf::Vector2f PlayerDirection = mPlayerReference.GetPosition() - mPosition;

			// Get Distance to player
			float PlayerDistance = 0.f;
			cSharedUtils::GetInstance().Magnitude(PlayerDirection, PlayerDistance);



			// If distance too far, chase player. If close, attack player.
			if (PlayerDistance < MIN_CHASE_DISTANCE)
			{
				mBehaviorAttack.UpdateInformation(PlayerDirection);
				mCurrentBehavior = &mBehaviorAttack;
				mIsShooting = true;
				mIsPlayerDetected = true;
				mHasAgro = true;
			}
			else
			{
				mBehaviorChase.UpdateInformation(PlayerDirection);
				mCurrentBehavior = &mBehaviorChase;
				mIsShooting = false;
				mIsPlayerDetected = true;
				mHasAgro = true;
			}
		}
		else
		{
			// Player not detected
			mIsShooting = false;
			
		}
	}
	else
	{
		// Player not in aim cone
		mIsShooting = false;
		mIsPlayerDetected = false;
	}
}

void cEnemyCharacter::UpdateWeapon(float _DeltaSeconds)
{
	mPistol.Update(_DeltaSeconds);

	// Shoot logic
	if (mIsShooting)
	{
		// get player position
		sf::Vector2f PlayerPosition = mPlayerReference.GetPosition();
		mPistol.FireWeapon(mPosition, PlayerPosition); // fire weapon at player position
		mIsShooting = true;
	}
}

void cEnemyCharacter::Update(float _DeltaSeconds)
{
	// Animate
	mAnimatorLegs.Animate(mBoxCollider.GetPosition(), _DeltaSeconds);
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
		// Character moving - legs should run
		mAnimatorLegs.SwapToRun();
	}
	else
	{
		// Character idle - legs should idle too
		mAnimatorLegs.SwapToIdle();
	}

	// Raycast viewcone // Character sees
	DetectPlayer();
	// HandleAgro
	HandleAgro(_DeltaSeconds);
	// Returning to spawn helper
	HandleReturnToSpawn(_DeltaSeconds);
	// Decide to shoot or not
	UpdateWeapon(_DeltaSeconds);
}

void cEnemyCharacter::HandleAgro(float _DeltaTime)
{
	// Enemy lost sight of player, tick down how long he will wait around
	if (mHasAgro && !mIsPlayerDetected)
		mChaseNoAgroTimer -= _DeltaTime;
	// enemy has agro and sees player, reset his goldfish brain
	else if (mHasAgro && mIsPlayerDetected)
		mChaseNoAgroTimer = mChaseNoAgroTimerMax;
	// Enemy has lost sight of player for too long, forgets about them
	if (mHasAgro && !mIsPlayerDetected && mChaseNoAgroTimer < 0.f)
	{
		mCurrentBehavior = &mBehaviorReturnToSpawn;
		mChaseNoAgroTimer = mChaseNoAgroTimerMax;
		mHasAgro = false;
	}
}

void cEnemyCharacter::HandleReturnToSpawn(float _DeltaTime)
{
	// No need to execute function if not returning to spawn
	if (mCurrentBehavior != &mBehaviorReturnToSpawn) return;

	// Update ReturnToSpawn Behavior information
	mBehaviorReturnToSpawn.UpdateInformation(mPosition);

	// Tick timer down
	mReturnToSpawnTimer -= _DeltaTime;

	// If enemy made it back to spawn, swap to patrol state
	if (mPosition.x < mSpawnPoint.x + 5.f && mPosition.x > mSpawnPoint.x - 5.f)
		if (mPosition.y < mSpawnPoint.y + 5.f && mPosition.y > mSpawnPoint.y - 5.f)
			mCurrentBehavior = &mBehaviorPatrol;

	// Timer allows enemy to return to patrol state if it can't make it back to spawn on its own
	if (mReturnToSpawnTimer <= 0.f)
	{
		mCurrentBehavior = &mBehaviorPatrol;
		mReturnToSpawnTimer = mReturnToSpawnTimerMax;
	}
}

void cEnemyCharacter::RespawnEnemy()
{
	mAlive = true;
	mAnimator.SwapToEnemyIdle();
	mCurrentBehavior = &mBehaviorPatrol;
	mEnemyMovementNormalized = sf::Vector2f(1.f, 0.f);
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
	mAnimatorLegs.ClearAnimation();

	// Track enemy death
	cLevelProgressTracker::GetInstance().ReduceEnemyCount();
}
