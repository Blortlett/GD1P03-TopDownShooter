#pragma once
#include <SFML/Graphics.hpp>

class cBehaviorPatrol
{
private:
	float mPatrolWaitTimerMax = 3.f;
	float mPatrolTimerMax = 3.f;
	float mPatrolTimer = mPatrolTimerMax;

	bool mIsEnemyWaiting = false;

	sf::Vector2f mEnemyMovementNormalized = { 1.f, 0.f };

public:
	cBehaviorPatrol();
	~cBehaviorPatrol() {}

	void GetMovementDirection(float _DeltaSeconds);
};