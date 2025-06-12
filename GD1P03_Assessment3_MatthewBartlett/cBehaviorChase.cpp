/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cBehaviorChase]
Description : [This class holds functionality to instruct enemy to chase player]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cBehaviorChase.h"
#include "cSharedUtils.h"

cBehaviorChase::cBehaviorChase()
{
}

void cBehaviorChase::GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds)
{
	//std::cout << "Behavior Chase Active" << std::endl;

	// Get movement direction towards player
	cSharedUtils::GetInstance().NormalizeVector(mDirectionToPlayer);
	_MovementDirection = mDirectionToPlayer;

	// Enemy should be moving
	_IsEnemyWaiting = false;
}
