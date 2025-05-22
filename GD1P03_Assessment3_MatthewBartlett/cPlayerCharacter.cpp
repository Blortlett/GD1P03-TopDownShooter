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


cPlayerCharacter::cPlayerCharacter(cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, sf::View& _PlayerCamera)
	: mRenderWindow(_GameWindow)
	, mPistol(_ProjectileManager)
	, mCameraView(_PlayerCamera)
{
	// Init player not at position 0,0
	//mPosition = { 300, 300 };

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

void cPlayerCharacter::Rotate()
{
	// Get mouse position relative to the window
	sf::Vector2i mousePixelPos = mPlayerInput.GetMousePosition(mRenderWindow);
	sf::Vector2f mouseWorldPos = mRenderWindow.mapPixelToCoords(mousePixelPos);

	// Calculate direction vector from player to mouse
	sf::Vector2f direction = mouseWorldPos - mPosition;

	// Calculate angle in radians and convert to degrees
	float angleRadians = std::atan2(direction.y, direction.x);
	float angleDegrees = angleRadians * 180.f / 3.14159265359f;

	// Adjust angle if necessary (e.g., if sprite's default facing direction is not right)
	// For example, if sprite faces up by default, add 90 degrees
	angleDegrees += 0.f; // Adjust based on your sprite's default orientation
	sf::Angle angle = sf::degrees(angleDegrees);

	// Apply rotation to animator (assumes cPlayerAnimator has a SetRotation method)
	mPlayerUpperBodyAnimator.SetRotation(angle);

	// Apply rotation to debug rectangle for testing
	mDebugRect.setRotation(angle);
}

void cPlayerCharacter::Move(float _DeltaSeconds)
{
	// Apply Friction to velocity when no input
	mVelocity = mVelocity * std::pow(PLAYER_FRICTION, _DeltaSeconds);

	// Apply input to move velocity
	mVelocity += mPlayerInputNormalized * PLAYER_ACCELERATION * _DeltaSeconds;

	// Clamp Move velocity
	mVelocity.x = std::min(std::max(mVelocity.x, -1 * PLAYER_MAX_VELOCITY), PLAYER_MAX_VELOCITY);
	mVelocity.y = std::min(std::max(mVelocity.y, -1 * PLAYER_MAX_VELOCITY), PLAYER_MAX_VELOCITY);

	// Apply Velocity to position
	mPosition += mVelocity * _DeltaSeconds;
}

void cPlayerCharacter::UpdateWeapon()
{
	if (mPlayerInput.IsLeftClickPressed() && !mIsShooting)
	{
		// Cast mouse position
		sf::Vector2i mouseScreenPosition = mPlayerInput.GetMousePosition(mRenderWindow);
		sf::Vector2f worldMousePosition = mRenderWindow.mapPixelToCoords(mouseScreenPosition, mCameraView);
		mPistol.FireWeapon(mPosition, worldMousePosition); // fire weapon at mouse position
		mIsShooting = true;
	}
	if (!mPlayerInput.IsLeftClickPressed())
		mIsShooting = false;
}

void cPlayerCharacter::Update(float _DeltaSeconds)
{
	// Input
	HandleInput();
	// Player Movement
	Move(_DeltaSeconds);
	Rotate();
	// Player Weapons
	UpdateWeapon();
	mPistol.Update(_DeltaSeconds);
	// Player animations
	mPlayerUpperBodyAnimator.Animate(mPosition, _DeltaSeconds);
	// Debug Update
	//mDebugRect.setPosition(mPosition);
}

void cPlayerCharacter::Draw()
{
	//mRenderWindow.draw(mDebugRect);
	mPlayerUpperBodyAnimator.Draw(mRenderWindow);
}