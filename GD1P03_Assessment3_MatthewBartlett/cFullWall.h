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