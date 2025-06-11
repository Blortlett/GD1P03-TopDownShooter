#pragma once
#include "cAnimatorBase.h"
#include "cEnemyIdleAnimation.h"
#include "cEnemyDeathAnimation.h"
#include "cEnemyPistolFireAnimation.h"

class cEnemyAnimator : public cAnimatorBase
{
public:
	cEnemyAnimator();
	~cEnemyAnimator() {}

	// Hide base functions
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds);
	void SetRotation(sf::Angle _AngleToRotate);

	// Swap animation functions
	void SwapToEnemyIdle(sf::Vector2f _CharacterPosition);
	void SwapToEnemyDeath(sf::Vector2f _CharacterPosition);
	void SwapToEnemyFire(sf::Vector2f _CharacterPosition);
private:
	// Animations
	cEnemyIdleAnimation mEnemyPistolIdle;
	cEnemyPistolFireAnimation mEnemyPistolFire;
	cEnemyDeathAnimation mEnemyDeath;

	bool mAnimationComplete = false;
};