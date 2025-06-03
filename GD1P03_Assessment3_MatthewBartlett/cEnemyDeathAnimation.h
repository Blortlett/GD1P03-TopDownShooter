#pragma once
#include "cPlayerAnimationBase.h"

class cEnemyDeathAnimation : public cPlayerAnimationBase
{
private:

public:
	cEnemyDeathAnimation();
	~cEnemyDeathAnimation() {}
	void Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds) override;
};