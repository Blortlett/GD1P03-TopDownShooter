#pragma once
#include "cAnimationBase.h"
#include "cPlayerUtils.h"

class cPlayerAnimationBase : public cAnimationBase
{
public:
	cPlayerAnimationBase(sf::Sprite _SpriteSheet)
		: cAnimationBase(_SpriteSheet)
	{
	}
};