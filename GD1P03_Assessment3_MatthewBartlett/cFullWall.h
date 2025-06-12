/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cFullWall]
Description : [This class can be placed in level to block characters and bullets moving through]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#pragma once
#include "cWallBase.h"

class cFullWall : public cWallBase
{
public:
	cFullWall(sf::FloatRect _Bounds)
		: cWallBase(_Bounds, sf::Color::Red)
	{}
	~cFullWall() {}
};