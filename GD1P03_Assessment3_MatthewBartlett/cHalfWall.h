/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cHalfWall]
Description : [This class can be placed in level to block characters moving through, but not bullets]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cWallBase.h"

class cHalfWall : public cWallBase
{
public:
	cHalfWall(sf::FloatRect _Bounds)
		: cWallBase(_Bounds, sf::Color::Yellow)
	{}
	~cHalfWall() {}
};