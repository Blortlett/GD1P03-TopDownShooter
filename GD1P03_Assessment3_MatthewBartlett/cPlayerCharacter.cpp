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

#include "cPlayerCharacter.h"


cPlayerCharacter::cPlayerCharacter()
{
	mPosition = { 300, 300 };

	// Debug stuff
	mDebugRect.setPosition(mPosition);
	mDebugRect.setFillColor(sf::Color::Green);
	mDebugRect.setSize(sf::Vector2f(30, 30));
	mDebugRect.setOrigin(mDebugRect.getSize() / 2.f);
}

void cPlayerCharacter::HandleInput()
{
	// Reset Input
	mPlayerInputNormalized = { 0, 0 };

	// -= Keyboard Input =-
	// Interperate up/down input
	if (mPlayerInput.IsMoveUpInputPressed())
		mPlayerInputNormalized.y -= 1.f;
	if (mPlayerInput.IsMoveDownInputPressed())
		mPlayerInputNormalized.y += 1.f;
	// Interperate left/right input
	if (mPlayerInput.IsMoveRightInputPressed())
		mPlayerInputNormalized.x += 1.f;
	if (mPlayerInput.IsMoveLeftInputPressed())
		mPlayerInputNormalized.x -= 1.f;

	// Normalize diagonal movement
	float magnitude = std::sqrt(mPlayerInputNormalized.x * mPlayerInputNormalized.x +
		mPlayerInputNormalized.y * mPlayerInputNormalized.y);
	if (magnitude > 0.f) 
	{
		mPlayerInputNormalized /= magnitude;
	}
}

void cPlayerCharacter::Move(float _DeltaSeconds)
{
	// Apply input to move velocity
	mVelocity += mPlayerInputNormalized * PLAYER_ACCELERATION * _DeltaSeconds;
	// Clamp Move velocity
	mVelocity.x = std::min(std::max(mVelocity.x, -1 * PLAYER_MAX_VELOCITY), PLAYER_MAX_VELOCITY);
	mVelocity.y = std::min(std::max(mVelocity.y, -1 * PLAYER_MAX_VELOCITY), PLAYER_MAX_VELOCITY);
	// Apply Velocity to position
	mPosition += mVelocity;
}

void cPlayerCharacter::Update(float _DeltaSeconds)
{
	HandleInput();
	Move(_DeltaSeconds);
	mPlayerUpperBodyAnimator.Animate(mPosition, _DeltaSeconds);
	//mDebugRect.setPosition(mPosition);
}

void cPlayerCharacter::Draw(sf::RenderWindow& _window)
{
	//_window.draw(mDebugRect);
	mPlayerUpperBodyAnimator.Draw(_window);
}
