/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cBehaviorAttack]
Description : [This class holds functionality to instruct enemy to attack player]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/


#pragma once
#include "iBehavior.h"

class cBehaviorAttack: public iBehavior
{
private:
	sf::Vector2f mDirectionToPlayer;
public:
	cBehaviorAttack();

	void GetMovementDirection(sf::Vector2f& _MovementDirection, bool& _IsEnemyWaiting, float _DeltaSeconds) override;
	void UpdateInformation(sf::Vector2f _DirectionToPlayer) { mDirectionToPlayer = _DirectionToPlayer; }
};