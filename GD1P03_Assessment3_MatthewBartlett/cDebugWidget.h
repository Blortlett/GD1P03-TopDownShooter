/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cDebugWidget]
Description : [cDebugWidget should be attatched to game objects with colliders. Collider should be passed in to the constructor of the debugWidget and this class will draw your collider out for you]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cBoxCollider.h"
#include <SFML/Graphics.hpp>
#include "cApplicationManager.h"

class cDebugWidget
{
private:
	// widget pos
	sf::Vector2f mWidgetPosition;

	// Collider reference
	cBoxCollider& mBoxCollider;

	// Shape for drawing collider
	sf::RectangleShape mColliderGraphic;

	void UpdateWidget();
public:
	cDebugWidget(cBoxCollider& boxCollider);
	~cDebugWidget();

	void DrawWidget(sf::RenderWindow& window);
};