#pragma once
#include "cAnimationBase.h"
#include "cPlayerUtils.h"

class cPlayerAnimationBase : public cAnimationBase
{
public:
	cPlayerAnimationBase(sf::Texture* _SpriteSheetTex)
		: cAnimationBase(_SpriteSheetTex)
	{
	}
};