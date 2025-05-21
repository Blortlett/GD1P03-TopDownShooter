#pragma once
#include "cBullet.h"
#include "cProjectileManager.h"

class cPistol
{
private:
	// Ammo Variables
	int mAmmoMax = 12;
	int mCurrentBulletIndex = mAmmoMax - 1;

	// Shooting & cooldown variables
	bool mCanShoot = true;
	float const mShootCooldownMax = .09f;
	float mCooldownTimer = mShootCooldownMax;

	// Manager References
	cProjectileManager& mProjectileManager;
public:
	cPistol(cProjectileManager& _ProjectileManager);
	~cPistol() {}

	void Update(float _DeltaTime);

	// Fire weapon function
	void FireWeapon(sf::Vector2f _FirePosition, sf::Vector2f _AimPosition);
	sf::Vector2f GetShootTrajectory(sf::Vector2f _FirePosition, sf::Vector2f _AimPosition);
};