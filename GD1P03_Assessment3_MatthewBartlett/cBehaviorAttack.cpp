#include "cBehaviorAttack.h"
#include "cSharedUtils.h"

cBehaviorAttack::cBehaviorAttack()
{

}

void cBehaviorAttack::GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds)
{
	//std::cout << "Behavior Attack Active" << std::endl;

	// Get movement direction towards player
	cSharedUtils::GetInstance().NormalizeVector(mDirectionToPlayer);
	_MovementDirection = mDirectionToPlayer;

	// Enemy should not move
	_IsEnemyWaiting = false;
}
