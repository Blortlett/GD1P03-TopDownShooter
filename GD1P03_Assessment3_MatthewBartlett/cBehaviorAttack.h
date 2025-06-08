#pragma once
#include "iBehavior.h"

class cBehaviorAttack: public iBehavior
{
private:
	sf::Vector2f mDirectionToPlayer;
public:
	cBehaviorAttack();
	~cBehaviorAttack() {}

	void GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds) override;
	void UpdateInformation(sf::Vector2f _DirectionToPlayer) { mDirectionToPlayer = _DirectionToPlayer; }
};