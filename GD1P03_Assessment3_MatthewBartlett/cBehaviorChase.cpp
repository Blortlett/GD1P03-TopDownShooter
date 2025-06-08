#include "cBehaviorChase.h"
#include "cSharedUtils.h"

cBehaviorChase::cBehaviorChase()
{
}

void cBehaviorChase::GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds)
{
	// Get movement direction towards player
	cSharedUtils::GetInstance().NormalizeVector(mDirectionToPlayer);
	_MovementDirection = mDirectionToPlayer;

	// Enemy should be moving
	_IsEnemyWaiting = false;
}
