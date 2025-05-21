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
	mCanShoot = false;
	mCooldownTimer = mShootCooldownMax;
}
