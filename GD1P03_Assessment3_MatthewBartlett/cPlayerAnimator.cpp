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
#include "cPlayerAnimator.h"

cPlayerAnimator::cPlayerAnimator()
{
    mCurrentAnimation = nullptr;
}

cPlayerAnimator::~cPlayerAnimator()
{
}

void cPlayerAnimator::Animate(sf::Vector2f PlayerPosition, float DeltaSeconds)
{
    mCurrentAnimation->Animate(PlayerPosition, DeltaSeconds);
}

void cPlayerAnimator::Draw(sf::RenderWindow& renderWindow)
{
    mCurrentAnimation->Draw(renderWindow);
}
