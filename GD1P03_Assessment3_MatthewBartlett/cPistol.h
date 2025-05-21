#pragma once
#include "cBullet.h"
#include "cProjectileManager.h"

class cPistol
{
private:
	// Ammo Variables
	int mAmmoMax = 12;
	int mAmmoRemaining = mAmmoMax;
	std::array<cBullet, 12> mBulletList;
	int mCurrentBulletIndex = 11;

	// Shooting & cooldown variables
	bool mCanShoot = true;
	float const mShootCooldownMax = .2f;
	float mCooldownTimer = mShootCooldownMax;

	// Manager References
	cProjectileManager& mProjectileManager;
public:
	cPistol(cProjectileManager& _ProjectileManager);
	~cPistol() {}

	void Update(float _DeltaTime);

	// Fire weapon function
	void FireWeapon(sf::Vector2f _FirePosition, sf::Vector2f _AimPosition);
};