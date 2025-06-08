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