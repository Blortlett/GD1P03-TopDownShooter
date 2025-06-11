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
#include "cGameSettings.h"


cPlayerCharacter::cPlayerCharacter(sf::Vector2f _StartPosition, cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow, sf::View& _PlayerCamera, cPlayerInput& _PlayerInput)
	: cCharacter(_StartPosition, _ProjectileManager, _GameWindow, true)
	, mCameraView(_PlayerCamera)
	, mPlayerInput(_PlayerInput)
	, mPlayerUpperBodyAnimator(this)
{
	mCharacterAnimator = &mPlayerUpperBodyAnimator;
	mCharacterAnimatorBottom = &mPlayerLegsAnimator;
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

	// Set animation depending on move input
	if (mPlayerInputNormalized == sf::Vector2f(0.f, 0.f))
	{
		// Set idle animation
		mPlayerLegsAnimator.SwapToIdle();
	}
	else
	{
		// Set Run animation
		mPlayerLegsAnimator.SwapToRun();
		
		// Rotate legs depending on input
		// Diagonals first
		// Left & Up  or  Right & Down
		if (mPlayerInputNormalized.x < 0.f && mPlayerInputNormalized.y < 0.f
			|| mPlayerInputNormalized.x > 0.f && mPlayerInputNormalized.y > 0.f)
			mPlayerLegsAnimator.SetRotation(sf::degrees(225));
		// Right & Up  or  Left & Down
		else if (mPlayerInputNormalized.x > 0.f && mPlayerInputNormalized.y < 0.f
			|| mPlayerInputNormalized.x < 0.f && mPlayerInputNormalized.y > 0.f)
			mPlayerLegsAnimator.SetRotation(sf::degrees(135));
		// 4 Cardinal directions next
		// Left or Right	// yInput == 0 becasue value is in left/right input
		else if (mPlayerInputNormalized.y == 0.f)
			mPlayerLegsAnimator.SetRotation(sf::degrees(0));
		// Up or Down	// xInput == 0 becasue all the value is in up/down input
		else if (mPlayerInputNormalized.x == 0.f)
			mPlayerLegsAnimator.SetRotation(sf::degrees(90));
	}
}

void cPlayerCharacter::GetLookTowardsDirection()
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
	mPlayerLookDirection = angle;
}

void cPlayerCharacter::UpdateWeapon(float _DeltaSeconds)
{
	if (mPlayerInput.IsLeftClickPressed() && !mIsShooting)
	{
		// Cast mouse position
		sf::Vector2i mouseScreenPosition = mPlayerInput.GetMousePosition(mRenderWindow);
		sf::Vector2f worldMousePosition = mRenderWindow.mapPixelToCoords(mouseScreenPosition, mCameraView);
		mPistol.FireWeapon(mPosition, worldMousePosition); // fire weapon at mouse position
		mIsShooting = true;
		mPlayerUpperBodyAnimator.SwapToPistolFire();
	}
	if (!mPlayerInput.IsLeftClickPressed())
		mIsShooting = false;
}

void cPlayerCharacter::RevivePlayer()
{
	mAlive = true;
	mPlayerUpperBodyAnimator.SwapToPistolIdle();
}

void cPlayerCharacter::OnCollision(sf::Vector2f direction)
{
	// Handle collision differently depending on direction
	if (direction.x < 0.0f)
	{
		// Collision on the right
		mVelocity.x = 0.f;
	}
	else if (direction.x > 0.0f)
	{
		// Collision on the left
		mVelocity.x = 0.f;
	}
	if (direction.y < 0.0f)
	{
		// Collision on the bottom
		mVelocity.y = 0.0f;
	}
	if (direction.y > 0.0f)
	{
		// Collision on the top
		mVelocity.y = 0.0f;
	}
}

void cPlayerCharacter::OnBulletCollision(sf::Vector2f direction)
{
	if (cGameSettings::GetInstance().mIsGodModeActive) return;
	mPlayerUpperBodyAnimator.SwapToPlayerDeath();
	mAlive = false;
}

void cPlayerCharacter::OnPickupPistolCollision()
{
	mPistol.RefillAmmo();
}

void cPlayerCharacter::Update(float _DeltaSeconds)
{
	// Player animations
	mPlayerUpperBodyAnimator.Animate(mPosition, _DeltaSeconds);
	mCharacterAnimatorBottom->Animate(mPosition, _DeltaSeconds);

	// Don't update anything except animations if player is dead
	if (!mAlive) return;

	// Input
	HandleInput();
	GetLookTowardsDirection();

	// Player Movement
	Move(mPlayerInputNormalized, _DeltaSeconds);
	// Player Rotation
	Rotate(mPlayerLookDirection);

	// Player Weapons
	UpdateWeapon(_DeltaSeconds);
	mPistol.Update(_DeltaSeconds);
}

void cPlayerCharacter::Draw()
{
	// Draw Player graphics
	if (mAlive) // only draw legs if character is alive
		mPlayerLegsAnimator.Draw(mRenderWindow);
	mPlayerUpperBodyAnimator.Draw(mRenderWindow);

	// Draw debug objects if debug is active
	if (cGameSettings::GetInstance().IsDebugActive())
		mDebugWidget.DrawWidget(mRenderWindow);
}

void cPlayerCharacter::SetPosition(sf::Vector2f _Position)
{
	mBoxCollider.MoveColliderPosition(_Position);
}
