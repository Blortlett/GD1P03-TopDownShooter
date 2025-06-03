#include "cAnimatorBase.h"

cAnimatorBase::cAnimatorBase(cAnimationBase& _StartAnimation)
{
	mCurrentAnimation = &_StartAnimation;
}

void cAnimatorBase::Animate(sf::Vector2f CharacterPosition, float DeltaSeconds)
{
	mCurrentAnimation->Animate(CharacterPosition, DeltaSeconds);
}

void cAnimatorBase::Draw(sf::RenderWindow& renderWindow)
{
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
