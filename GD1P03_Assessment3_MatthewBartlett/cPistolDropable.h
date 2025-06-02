#pragma once
#include "cSharedUtils.h"
#include "cBoxCollider.h"

class cPistolDropable
{
private:
	// Collider & position
	cBoxCollider mCollider;

	// velocity
	sf::Vector2f mVelocity;
	float mThrowSpeed = 10.f;
	float const FRICTION = .005f;

	// Record Ammo count
	int mAmmoCount;

	// Sprite
	sf::Sprite mPistolSprite;

public:
	cPistolDropable(sf::Vector2f _Postion, sf::Vector2f _NormalizedThrowDirection, int _AmmoCount);
	~cPistolDropable() {}

	void OnCollision();

	void Update(float _DeltaTime);
	void Draw(sf::RenderWindow& _GameWindow);
};