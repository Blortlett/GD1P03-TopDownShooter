#include "cPickupManager.h"

cPickupManager::cPickupManager(cPlayerCharacter& _PlayerCharacter, sf::RenderWindow& _GameWindow)
    : mGameWindow(_GameWindow)
    , mPlayerCharacter(_PlayerCharacter)
{

}

cPickupManager::~cPickupManager()
{
    // Delete each weapon
    for (cPistolDropable* weapon : mDroppedWeaponList)
    {
        delete weapon;
    }
    // Clear vector list
    mDroppedWeaponList.clear();
}

void cPickupManager::Update(float _DeltaTime)
{
    // Check if player picked up weapon
    CheckPlayerPickup();

    // Draw / update dropped weapon
    for (cPistolDropable* weapon : mDroppedWeaponList)
    {
        weapon->Update(_DeltaTime);
        weapon->Draw(mGameWindow);
    }
}

void cPickupManager::CreateNewWeaponDrop(sf::Vector2f _Postion, sf::Angle _ThrowDirection, int _AmmoCount)
{
    // Create new weapon
    cPistolDropable* newWeapon = new cPistolDropable(_Postion, _ThrowDirection, _AmmoCount);
    // Add new weapon to dropped weapons list
    mDroppedWeaponList.push_back(newWeapon);
}

void cPickupManager::CheckPlayerPickup()
{
    for (size_t i = 0; i < mDroppedWeaponList.size(); ++i)
    {
        if (mDroppedWeaponList[i]->CheckCollisionWithPlayer(mPlayerCharacter))
        {
            delete mDroppedWeaponList[i];
            mDroppedWeaponList.erase(mDroppedWeaponList.begin() + i);
            return; // End it here..
        }
    }
}

void cPickupManager::ClearDrops()
{
    // Delete each weapon
    for (cPistolDropable* weapon : mDroppedWeaponList)
    {
        delete weapon;
    }
    // Clear vector list
    mDroppedWeaponList.clear();
}
