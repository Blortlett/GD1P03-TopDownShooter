/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cRaycaster]
Description : [This class holds functionality for my shoddy raycaster functionality - probably my favorite part of this project]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class cCharacter;
class cFullWall;

class cRaycaster
{
private:
	float const mCastDistance = 350.f;
	float mCastIncremement = 5.f;
	float mCurrentCastDist = 0.f;
	sf::RectangleShape mDebugLine;

	// Player Character Reference - Detectable
	cCharacter& mCharacter;
	// Walls to check against - Detectable
	std::vector<cFullWall*>* mLevelWalls;

public:
	cRaycaster(cCharacter& _Detectable);
	~cRaycaster() {}

	bool Cast(sf::Vector2f _Origin, sf::Angle _Angle);
	void DebugDraw(sf::RenderWindow& _Window);
};