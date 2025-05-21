#include "cPistol.h"

cPistol::cPistol()
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
	if (mAmmoRemaining <= 0) return; // return for now, add empty clip sound here later tho

	// Debug
	std::cout << "Gun says: Bang Bang!" << std::endl;

	// call fire bullet here
	mBulletList[mCurrentBulletIndex].Fire(_FirePosition, _AimPosition);

	mCurrentBulletIndex--;
	mAmmoRemaining--;
	mCanShoot = false;
	mCooldownTimer = mShootCooldownMax;
}
