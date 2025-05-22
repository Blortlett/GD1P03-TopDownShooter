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
#include "cBaseDrawTool.h"

cBaseDrawTool::cBaseDrawTool(cLevelManager& _LevelManager)
	: mLevelManager(_LevelManager)
{

}
cBaseDrawTool::~cBaseDrawTool()
{
	
}


// Draw function		// To game renderwindow
void cBaseDrawTool::DrawToolToScreen(sf::RenderWindow& window)
{
	window.draw(mRectShape);
}
// Update function		// Move tool around screen
void cBaseDrawTool::UpdateCursor(sf::Vector2f& mousePos)
{
	mRectShape.setPosition(mousePos);
}