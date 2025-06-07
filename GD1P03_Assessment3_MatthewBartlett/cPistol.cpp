#include "cPistol.h"
#include "cProjectileManager.h"
#include "cAudioManager.h"

cPistol::cPistol(cProjectileManager& _ProjectileManager)
	: mProjectileManager(_ProjectileManager)
{
	
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

void cPistol::FireWeapon(sf::Vector2f _FirePosition, sf::Vector2f _AimPosition)
{
	// Returns for if gun is not in fire state
	if (!mCanShoot) return; // Don't bother if weapon is on cooldown 
	if (mCurrentBulletIndex < 0)
	{
		// empty clip sound
		cAudioManager::GetInstance().SFXPlayDryFire();
		return; // do not fire!
	}

	// Fire Bullet here
	sf::Vector2f ShootTrajectory = GetShootTrajectory(_FirePosition, _AimPosition);
	mProjectileManager.FirePlayerBullet(_FirePosition, ShootTrajectory);

	// Set variables to just fired mode
	mCurrentBulletIndex--;
	mCanShoot = false;
	mCooldownTimer = mShootCooldownMax;

	// Play audio sound
	cAudioManager::GetInstance().SFXPlayShoot();
}

sf::Vector2f cPistol::GetShootTrajectory(sf::Vector2f _FirePosition, sf::Vector2f _AimPosition)
{
	_FirePosition = _FirePosition; // Set position to fire point
	sf::Vector2f ShootDirection = _AimPosition - _FirePosition; // Calculate aimed direction
	cSharedUtils::NormalizeVector(ShootDirection); // normalize direction
	return ShootDirection;
}
