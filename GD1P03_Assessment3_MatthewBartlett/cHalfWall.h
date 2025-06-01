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