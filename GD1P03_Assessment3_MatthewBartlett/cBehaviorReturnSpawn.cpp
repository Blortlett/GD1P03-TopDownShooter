#include "cBehaviorReturnSpawn.h"
#include "cSharedUtils.h"

cBehaviorReturnToSpawn::cBehaviorReturnToSpawn(sf::Vector2f _SpawnPosition)
	: mSpawnPosition(_SpawnPosition)
{
}

void cBehaviorReturnToSpawn::UpdateInformation(sf::Vector2f _CurrentPosition)
{
	mCurrentPosition = _CurrentPosition;
}

void cBehaviorReturnToSpawn::GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds)
{
	// Get Direction
	sf::Vector2f vectorToMove = mSpawnPosition - mCurrentPosition;
	// Normalize Direction
	cSharedUtils::GetInstance().NormalizeVector(vectorToMove);

	// Return Values
	_MovementDirection = vectorToMove;
	_IsEnemyWaiting = false;
}
