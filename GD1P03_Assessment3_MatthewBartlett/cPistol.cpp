#include "cPistol.h"
#include "cProjectileManager.h"
#include "cAudioManager.h"
#include "cGameSettings.h"

cPistol::cPistol(bool _IsPlayerWeapon, cProjectileManager& _ProjectileManager)
	: mProjectileManager(_ProjectileManager)
	, mIsPlayerWeapon(_IsPlayerWeapon)
{
	// Set initial cooldown timer per owner character
	if (mIsPlayerWeapon)
		mCooldownTimer = mPlayerShootCooldownMax;
	else
		mCooldownTimer = mEnemyShootCooldownMax;
}

void cPistol::Update(float _DeltaTime)
{
	if (mCooldownTimer >= 0.f)
	{
		mCooldownTimer -= _DeltaTime;
	}
	else
		mCanShoot = true;
}

bool cPistol::FireWeapon(sf::Vector2f _FirePosition, sf::Vector2f _AimPosition)
{
	// Returns for if gun is not in fire state
	if (!mCanShoot) return false; // Don't bother if weapon is on cooldown 
	if (mCurrentBulletIndex < 0)
	{
		// empty clip sound
		cAudioManager::GetInstance().SFXPlayDryFire();
		return false;
	} 
	else
	{
		// Fire Bullet here
		cAudioManager::GetInstance().SFXPlayShoot();
		sf::Vector2f ShootTrajectory = GetShootTrajectory(_FirePosition, _AimPosition);
		sf::Vector2f correctFirePosition = _FirePosition + (ShootTrajectory * 15.f);
		if (mIsPlayerWeapon)
			mProjectileManager.FirePlayerBullet(correctFirePosition, ShootTrajectory);
		else
			mProjectileManager.FireEnemyBullet(correctFirePosition, ShootTrajectory);
	}

	// Set variables to just fired mode
	if (!cGameSettings::GetInstance().mIsInfiniteAmmoActive)
		mCurrentBulletIndex--;
	mCanShoot = false;
	if (mIsPlayerWeapon)
		mCooldownTimer = mPlayerShootCooldownMax;
	else
		mCooldownTimer = mEnemyShootCooldownMax;

	return true;
}

sf::Vector2f cPistol::GetShootTrajectory(sf::Vector2f _FirePosition, sf::Vector2f _AimPosition)
{
	_FirePosition = _FirePosition; // Set position to fire point
	sf::Vector2f ShootDirection = _AimPosition - _FirePosition; // Calculate aimed direction
	cSharedUtils::NormalizeVector(ShootDirection); // normalize direction
	return ShootDirection;
}

void cPistol::RefillAmmo()
{
	mCurrentBulletIndex = mAmmoMax - 1;
	cAudioManager::GetInstance().SFXPlayPistolRack();
}
