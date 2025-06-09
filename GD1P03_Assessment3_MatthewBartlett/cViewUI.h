#pragma once
#include <SFML/Graphics.hpp>

class cViewUI
{
private:
	sf::View UICanvas;


public:
	cViewUI();
	~cViewUI() {}

	void SetAmmoUIValues();
};