/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cPickupManager]
Description : [This class holds a vector list of all dropped weapons. Also allows functionality like cleanup for and adding to that list]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cPistolDropable.h"

class cPlayerCharacter;

class cPickupManager
{
private:
	// List of weapon pickups
	std::vector<cPistolDropable*> mDroppedWeaponList;

	// Player Reference
	cPlayerCharacter& mPlayerCharacter;
	// Game window reference
	sf::RenderWindow& mGameWindow;

public:
	cPickupManager(cPlayerCharacter& _PlayerCharacter, sf::RenderWindow& _GameWindow);
	~cPickupManager();

	void Update(float _DeltaTime);

	void CreateNewWeaponDrop(sf::Vector2f _Postion, sf::Angle _ThrowDirection, int _AmmoCount);

	void CheckPlayerPickup();

	void ClearDrops();
};