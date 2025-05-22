/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cBaseDrawTool]
Description : [This class is inherited by all draw tools. Provides functions to be called by the cEditorDrawTool (the manager class)]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include "cBoxCollider.h"
#include "cLevelManager.h"

class cBaseDrawTool
{
public:
	// Constructors
	cBaseDrawTool(cLevelManager& _LevelManager);
	~cBaseDrawTool();

	// Draw tool to GameWindow function // Draw Function
	void DrawToolToScreen(sf::RenderWindow& window);
	// Update function
	void UpdateCursor(sf::Vector2f& mousePos);

	// Extendables... Do they need to be? I think so...
	virtual void UseTool(sf::Vector2f& mousePos) = 0;
	virtual void CompleteUseTool() = 0;
protected:
	
	sf::RectangleShape mRectShape;
	cLevelManager& mLevelManager;
};