#include "cPickupManager.h"

cPickupManager::cPickupManager(sf::RenderWindow& _GameWindow)
    : mGameWindow(_GameWindow)
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
    for (cPistolDropable* weapon : mDroppedWeaponList)
    {
        weapon->Update(_DeltaTime);
        weapon->Draw(mGameWindow);
    }
}

void cPickupManager::CreateNewWeaponDrop(sf::Vector2f _Postion, sf::Angle _ThrowDirection, int _AmmoCount)
{
    std::cout << "Creating Pistol Drop" << std::endl;
    // Create new weapon
    cPistolDropable* newWeapon = new cPistolDropable(_Postion, _ThrowDirection, _AmmoCount);
    // Add new weapon to dropped weapons list
    mDroppedWeaponList.push_back(newWeapon);
}
