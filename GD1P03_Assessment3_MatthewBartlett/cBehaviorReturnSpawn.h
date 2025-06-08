#pragma once
#include "iBehavior.h"

class cBehaviorReturnToSpawn: public iBehavior
{
private:
	sf::Vector2f mSpawnPosition;
public:
	cBehaviorReturnToSpawn(sf::Vector2f _SpawnPosition);
	~cBehaviorReturnToSpawn() {}

	void GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds) override;
};