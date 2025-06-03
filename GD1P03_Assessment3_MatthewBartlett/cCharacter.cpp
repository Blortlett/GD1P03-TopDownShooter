#include "cCharacter.h"
#include "cGameSettings.h"

cCharacter::cCharacter(sf::Vector2f _Position, cProjectileManager& _ProjectileManager, sf::RenderWindow& _GameWindow)
	: mRenderWindow(_GameWindow)
	, mPistol(_ProjectileManager)
	, mPosition(_Position)
	, mBoxCollider(sf::FloatRect(_Position, { 24.f, 24.f }))
	, mDebugWidget(mBoxCollider)
{
}

void cCharacter::Rotate(sf::Vector2f _FaceTowards)
{
	// Calculate direction vector from character to _FaceTowards position
	sf::Vector2f direction = _FaceTowards - mPosition;

	// Calculate angle in radians and convert to degrees
	float angleRadians = std::atan2(direction.y, direction.x);
	float angleDegrees = angleRadians * 180.f / 3.14159265359f;

	// Adjust angle if necessary (e.g., if sprite's default facing direction is not right)
	// For example, if sprite faces up by default, add 90 degrees
	angleDegrees += 0.f; // Adjust based on your sprite's default orientation
	sf::Angle angle = sf::degrees(angleDegrees);

	// Apply rotation to animator (assumes cPlayerAnimator has a SetRotation method)
	mCharacterAnimator->SetRotation(angle);
}

void cCharacter::Move(sf::Vector2f _NormalizedDirection, float _DeltaSeconds)
{
	// Apply Friction to velocity when no input
	mVelocity = mVelocity * std::pow(PLAYER_FRICTION, _DeltaSeconds);

	// Apply input to move velocity
	mVelocity += _NormalizedDirection * PLAYER_ACCELERATION * _DeltaSeconds;

	// Clamp Move velocity
	mVelocity.x = std::min(std::max(mVelocity.x, -1 * PLAYER_MAX_VELOCITY), PLAYER_MAX_VELOCITY);
	mVelocity.y = std::min(std::max(mVelocity.y, -1 * PLAYER_MAX_VELOCITY), PLAYER_MAX_VELOCITY);

	// Apply Velocity to position
	mBoxCollider.MoveColliderPosition(mBoxCollider.GetPosition() + mVelocity * _DeltaSeconds);

	// Apply Collider position to position // wrong way my dude
	mPosition = mBoxCollider.GetPosition();
}

void cCharacter::OnCollision(sf::Vector2f direction)
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

void cCharacter::Draw()
{
	// Draw character graphics
	mCharacterAnimator->Draw(mRenderWindow);
	// Draw debug objects if debug is active
	if (cGameSettings::GetInstance().IsDebugActive())
		mDebugWidget.DrawWidget(mRenderWindow);
}
