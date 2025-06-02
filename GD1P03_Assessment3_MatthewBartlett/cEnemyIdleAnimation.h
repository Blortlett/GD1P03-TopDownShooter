#pragma once
#include "cPlayerAnimationBase.h"

class cEnemyIdleAnimation : public cPlayerAnimationBase
{
private:

public:
	cEnemyIdleAnimation();
	~cEnemyIdleAnimation() {}
	void Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds) override;
};