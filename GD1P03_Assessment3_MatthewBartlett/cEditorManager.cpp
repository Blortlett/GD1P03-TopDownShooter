/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cEditorDrawTool]
Description : [This class has all draw tools as member variables and provides a state machine to switch between editor tools]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cEditorManager.h"

cEditorManager::cEditorManager(sf::RenderWindow& _GameWindow, cLevelManager& _LevelManager, sf::View _PlayerCameraView)
	: mGameWindow(_GameWindow)
	, mFullWallTool(_LevelManager)
	, mCameraView(_PlayerCameraView)
{
	mCurrentTool = &mFullWallTool;
}

void cEditorManager::SetTool(ToolType type)
{
	switch (type)
	{
	case cEditorManager::ToolType::ToolMode_FullWall:
		mCurrentTool = &mFullWallTool;
		break;
	/*
	case cEditorManager::ToolType::ToolMode_HalfWall:
		mActiveTool = &mRectangleTool;
		break;
	*/
	}
}

void cEditorManager::UpdateCursor()
{
	sf::Vector2i mouseScreenPosition = sf::Mouse::getPosition(mGameWindow);
	//sf::Vector2f worldMousePosition = mGameWindow.mapPixelToCoords(mouseScreenPosition, mCameraView);
	std::cout << "MousePosi: " << mouseScreenPosition.x << "X" << mouseScreenPosition.y << std::endl;
	//std::cout << "MousePosf: " << worldMousePosition.x << "X" << worldMousePosition.y << std::endl;

	// Left Click
	if (mPlayerInput.IsLeftClickPressed() && mGameWindow.hasFocus())
	{
		//UseTool(worldMousePosition);
		mIsDrawing = true;
	}
	else
	{
		if (mIsDrawing)
		{
			CompleteUseTool();
			mIsDrawing = false;
		}
		else
		{
			//mCurrentTool->UpdateCursor(worldMousePosition);
		}
	}
}

void cEditorManager::UseTool(sf::Vector2f& toolPosition)
{
	toolPosition.x += mGridSize;
	toolPosition.y += mGridSize;
	mCurrentTool->UseTool(toolPosition);
}

void cEditorManager::DrawCursorToScreen(sf::RenderWindow& window)
{
	mCurrentTool->DrawToolToScreen(window);
}

void cEditorManager::CompleteUseTool()
{
	mCurrentTool->CompleteUseTool();
}

