#pragma once
#include "cBullet.h"

class cPistol
{
private:
	// Ammo Variables
	int mAmmoMax = 12;
	int mAmmoRemaining = mAmmoMax;
	std::array<cBullet, 12> mBulletList;
	int mCurrentBulletIndex = 0;

	// Shooting & cooldown variables
	bool mCanShoot = true;
	float const mShootCooldownMax = .2f;
	float mCooldownTimer = mShootCooldownMax;

public:
	cPistol();
	~cPistol() {}

	void Update(float _DeltaTime);

	// Fire weapon function
	void FireWeapon(sf::Vector2f _FirePosition, sf::Vector2f _AimPosition);
};