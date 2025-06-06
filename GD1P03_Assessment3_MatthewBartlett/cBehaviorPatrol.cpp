#include "cBehaviorPatrol.h"

cBehaviorPatrol::cBehaviorPatrol()
{
}

void cBehaviorPatrol::GetMovementDirection(float _DeltaSeconds)
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
