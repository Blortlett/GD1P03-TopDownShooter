#pragma once
#include "cPlayerAnimationBase.h"

class cPlayerDeathAnimation : public cPlayerAnimationBase
{
private:

public:
	cPlayerDeathAnimation();
	~cPlayerDeathAnimation() {}
	void Animate(sf::Vector2f _PlayerPosition, float _DeltaSeconds) override;
};