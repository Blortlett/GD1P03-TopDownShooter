/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPlayerCharacter]
Description : [This class functions as the player controller]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include "cPlayerInput.h"
#include "cPlayerAnimator.h"
#include "cPlayerUtils.h"


class cPlayerCharacter
{
private:
	cPlayerInput mPlayerInput;
	cPlayerAnimator mPlayerUpperBodyAnimator;
public:
	cPlayerCharacter();
	~cPlayerCharacter() {}
};