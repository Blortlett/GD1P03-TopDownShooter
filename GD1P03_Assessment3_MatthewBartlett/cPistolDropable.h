#pragma once
#include "cSharedUtils.h"
#include "cBoxCollider.h"
#include "cDebugWidget.h"

class cPlayerCharacter;

class cPistolDropable
{
private:
	// Collider & position
	cBoxCollider mCollider;
	cDebugWidget mDebugWidget;

	// velocity
	sf::Vector2f mVelocity;
	float mThrowSpeed = .1f;
	float const FRICTION = .005f;

	// Record Ammo count
	int mAmmoCount;

	// Sprite
	sf::Sprite mPistolSprite;

public:
	cPistolDropable(sf::Vector2f _Postion, sf::Angle _ThrowDirection, int _AmmoCount);
	~cPistolDropable() {}

	bool CheckCollisionWithPlayer(cPlayerCharacter& _Character);

	void Update(float _DeltaTime);
	void Draw(sf::RenderWindow& _GameWindow);
};