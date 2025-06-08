#include "cProjectileManager.h"

cProjectileManager::cProjectileManager(sf::RenderWindow& _Window)
    : mGameWindow(_Window)
{
}

void cProjectileManager::FirePlayerBullet(sf::Vector2f _StartPosition, sf::Vector2f _ShootTrajectory)
{
    // Call .Fire() function on bullet in list
	mPlayerBulletList[mPlayerCurrentBulletIndex].Fire(_StartPosition, _ShootTrajectory);

    // Decrement player bullet index / Move to next bullet in list
    mPlayerCurrentBulletIndex--;
    if (mPlayerCurrentBulletIndex < 0) // Reset next active bullet to top of the list
        mPlayerCurrentBulletIndex = mPlayerMaxBulletIndex;
}

void cProjectileManager::FireEnemyBullet(sf::Vector2f _StartPosition, sf::Vector2f _ShootTrajectory)
{
    // Call .Fire() function on bullet in list
    mEnemyBulletList[mPlayerCurrentBulletIndex].Fire(_StartPosition, _ShootTrajectory);

    // Decrement enemy bullet index / Move to next bullet in list
    mEnemyCurrentBulletIndex--;
    if (mEnemyCurrentBulletIndex < 0) // Reset next active bullet to top of the list
        mEnemyCurrentBulletIndex = mEnemyMaxBulletIndex;
}

void cProjectileManager::Update(float _DeltaTime)
{
    for (auto& bullet : mPlayerBulletList)
    {
        bullet.Update(mGameWindow, _DeltaTime);
    }

    for (auto& bullet : mEnemyBulletList)
    {
        bullet.Update(mGameWindow, _DeltaTime);
    }
}

std::array<cBullet, 15>& cProjectileManager::GetPlayerBulletList()
{
    return mPlayerBulletList;
}
