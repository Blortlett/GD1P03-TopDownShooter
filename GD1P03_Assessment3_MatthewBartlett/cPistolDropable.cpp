#include "cPistolDropable.h"

cPistolDropable::cPistolDropable(sf::Vector2f _Postion, sf::Angle _ThrowDirection, int _AmmoCount)
	: mPistolSprite(cSharedUtils::GetInstance().mPistolTex)
	, mCollider(sf::FloatRect(_Postion, {30, 20}))
	, mAmmoCount(_AmmoCount)
{
	mPistolSprite.setScale(sf::Vector2f(.5f, .5f));

	// center sprite
	mPistolSprite.setOrigin(mPistolSprite.getLocalBounds().size / 2.f);

	// Init velocity
	mVelocity = sf::Vector2f(
		std::cos(_ThrowDirection.asRadians()) * mThrowSpeed,
		std::sin(_ThrowDirection.asRadians()) * mThrowSpeed
	);
}

void cPistolDropable::OnCollision()
{
}

void cPistolDropable::OnPickup()
{
	
}

void cPistolDropable::Update(float _DeltaTime)
{
	// Apply Friction to velocity when no input
	mVelocity = mVelocity * std::pow(FRICTION, _DeltaTime);
	// update position
	mCollider.MoveColliderPosition(mCollider.GetPosition() + mVelocity);
	// update sprite position
	mPistolSprite.setPosition(mCollider.GetPosition());
}

void cPistolDropable::Draw(sf::RenderWindow& _GameWindow)
{
	_GameWindow.draw(mPistolSprite);
}
