#include "cPickupManager.h"

cPickupManager::cPickupManager()
{

}

cPickupManager::~cPickupManager()
{
    for (cPistolDropable* weapon : mDroppedWeaponList)
    {
        delete weapon;
    }
    mDroppedWeaponList.clear();
}

void cPickupManager::Update()
{

}
