#pragma once
#pragma once
#include "iBehavior.h"

class cBehaviorAttack: public iBehavior
{
private:

public:
	cBehaviorAttack();
	~cBehaviorAttack() {}

	void GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds) override;
};