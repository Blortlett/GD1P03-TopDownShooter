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
	void SwapToEnemyDeath();
private:
	// Animations
	cEnemyIdleAnimation mEnemyPistolIdle;
	cEnemyDeathAnimation mEnemyDeath;
};