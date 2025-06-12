/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerAnimator]
Description : [This class swaps between and displays animation states for the player character]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cAnimatorBase.h"
#include "cAnimationPistolIdle.h"
#include "cAnimationPistolFire.h"
#include "cPlayerDeathAnimation.h"
#include "cAnimationPlayerPunch.h"

class cCharacter;

class cPlayerAnimator : public cAnimatorBase
{
private:
	// Animations
	cAnimationPistolIdle mUpperPistolIdle;
	cAnimationPistolFire mUpperPistolFire;
	cAnimationPlayerPunch mPlayerPunchAnimation;
	cPlayerDeathAnimation mPlayerDeathAnimation;

	bool mAnimationComplete = false;

public:
	 // Constructors
	cPlayerAnimator(cCharacter* _OwnerCharacter);
	~cPlayerAnimator();

	// Hide base functions
	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds);
	void SetRotation(sf::Angle _AngleToRotate);

	void SwapToPistolFire(sf::Vector2f _PlayerPosition);
	void SwapToPistolIdle(sf::Vector2f _PlayerPosition);
	void SwapToPlayerPunch(sf::Vector2f _PlayerPosition);
	void SwapToPlayerDeath(sf::Vector2f _PlayerPosition);

	bool IsPunching() { return mCurrentAnimation == &mPlayerPunchAnimation; }
};