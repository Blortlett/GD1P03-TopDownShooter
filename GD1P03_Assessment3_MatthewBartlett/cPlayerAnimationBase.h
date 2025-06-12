/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerAnimationBase]
Description : [this class is the base class all player animations classes inherit from. Basically it just includes cPlayerUtils]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

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