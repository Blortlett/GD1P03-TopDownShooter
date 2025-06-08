#include "cBehaviorPatrol.h"

cBehaviorPatrol::cBehaviorPatrol()
{
}

void cBehaviorPatrol::GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds)
{
	// Countdown timer
	mPatrolTimer -= _DeltaSeconds;
	// On Timer loop
	if (mPatrolTimer <= 0.f)
	{
		if (_IsEnemyWaiting)
		{ // Wait timer expired, change directions
			_MovementDirection.x *= -1;
			// Set enemy to patrolling
			_IsEnemyWaiting = false;
			// Reset timer
			mPatrolTimer = mPatrolTimerMax;
		}
		else
		{ // Patrol timer expired, get to waiting
			_IsEnemyWaiting = true;
			mPatrolTimer = mPatrolWaitTimerMax;
		}
	}
}
