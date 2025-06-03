#pragma once
#include "cPistolDropable.h"

class cPickupManager
{
private:
	// List of weapon pickups
	std::vector<cPistolDropable*> mDroppedWeaponList;
	// Game window reference
	sf::RenderWindow& mGameWindow;

public:
	cPickupManager(sf::RenderWindow& _GameWindow);
	~cPickupManager();

	void Update(float _DeltaTime);

	void CreateNewWeaponDrop(sf::Vector2f _Postion, sf::Angle _ThrowDirection, int _AmmoCount);
};