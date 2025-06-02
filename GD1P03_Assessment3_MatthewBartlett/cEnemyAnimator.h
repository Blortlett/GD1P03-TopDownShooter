#pragma once
#include "cAnimatorBase.h"
#include "cEnemyIdleAnimation.h"

class cEnemyAnimator : public cAnimatorBase
{
public:
	cEnemyAnimator();
	~cEnemyAnimator();
private:
	// Animations
	cEnemyIdleAnimation mEnemyPistolIdle;
};