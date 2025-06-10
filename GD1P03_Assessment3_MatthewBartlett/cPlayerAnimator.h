/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimator]
Description : [Any object that would like to have animations should have a cAnimator member object attatched to it. This class can switch, animate and display animations]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cAnimatorBase.h"
#include "cAnimationPistolIdle.h"
#include "cAnimationPistolFire.h"
#include "cPlayerDeathAnimation.h"

class cCharacter;

class cPlayerAnimator : public cAnimatorBase
{
private:
	// Animations
	cAnimationPistolIdle mUpperPistolIdle;
	cAnimationPistolFire mUpperPistolFire;
	cPlayerDeathAnimation mPlayerDeathAnimation;

	bool mAnimationComplete = false;

public:
	 // Constructors
	cPlayerAnimator(cCharacter* _OwnerCharacter);
	~cPlayerAnimator();

	void Animate(sf::Vector2f PlayerPosition, float DeltaSeconds);

	void SwapToPistolFire();
	void SwapToPistolIdle();
	void SwapToPlayerDeath();
};