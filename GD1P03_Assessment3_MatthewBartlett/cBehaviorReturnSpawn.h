/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cBehaviorReturnToSpawn]
Description : [This class holds functionality to instruct enemy to return to it's spawn position]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "iBehavior.h"

class cBehaviorReturnToSpawn: public iBehavior
{
private:
	sf::Vector2f mSpawnPosition;
	sf::Vector2f mCurrentPosition;
public:
	cBehaviorReturnToSpawn(sf::Vector2f _SpawnPosition);
	~cBehaviorReturnToSpawn() {}

	void UpdateInformation(sf::Vector2f _CurrentPosition);
	void GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds) override;
};