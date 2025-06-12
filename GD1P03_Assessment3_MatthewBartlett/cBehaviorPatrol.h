/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cBehaviorPatrol]
Description : [This class holds functionality to instruct enemy to patrol level area]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "iBehavior.h"

class cBehaviorPatrol : public iBehavior
{
private:
	float mPatrolWaitTimerMax = 3.f;
	float mPatrolTimerMax = 3.f;
	float mPatrolTimer = mPatrolTimerMax;

public:
	cBehaviorPatrol();
	~cBehaviorPatrol() {}

	void GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds) override;
};