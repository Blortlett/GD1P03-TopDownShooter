/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimatorBase]
Description : [This base class can be extended by animator classes to swap between and display animation states on an object]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cAnimatorBase.h"

cAnimatorBase::cAnimatorBase(cAnimationBase& _StartAnimation)
{
	mCurrentAnimation = &_StartAnimation;
}

void cAnimatorBase::Animate(sf::Vector2f CharacterPosition, float DeltaSeconds)
{
	if (mCurrentAnimation)
		mCurrentAnimation->Animate(CharacterPosition, DeltaSeconds);
}

void cAnimatorBase::Draw(sf::RenderWindow& renderWindow)
{
	if (mCurrentAnimation)
		mCurrentAnimation->Draw(renderWindow);
}

void cAnimatorBase::SetRotation(sf::Angle _AngleToRotate)
{
	mCurrentAnimation->RotateAnimation(_AngleToRotate);
}

void cAnimatorBase::SwapAnimation(cAnimationBase* _Animation)
{
	mCurrentAnimation = _Animation;
}

sf::Angle cAnimatorBase::GetRotation()
{
	return mCurrentAnimation->GetRotation();
}
