#pragma once
#include "cAnimatorBase.h"
#include "cEnemyIdleAnimation.h"
#include "cEnemyDeathAnimation.h"

class cEnemyAnimator : public cAnimatorBase
{
public:
	cEnemyAnimator();
	~cEnemyAnimator() {}

	// Swap animation functions
	void SwapToEnemyIdle(sf::Vector2f _CharacterPosition);
	void SwapToEnemyDeath(sf::Vector2f _CharacterPosition);
private:
	// Animations
	cEnemyIdleAnimation mEnemyPistolIdle;
	cEnemyDeathAnimation mEnemyDeath;
};