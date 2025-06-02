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
#include "cGameSettings.h"

cEditorManager::cEditorManager(sf::RenderWindow& _GameWindow, cLevelManager& _LevelManager, sf::View& _PlayerCameraView)
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
	// Return if debug mode is not active - do not draw diddly squat
	if (cGameSettings::GetInstance().IsDebugActive())
		return;


	sf::Vector2i mouseScreenPosition = sf::Mouse::getPosition(mGameWindow);
	sf::Vector2f worldMousePosition = mGameWindow.mapPixelToCoords(mouseScreenPosition, mCameraView);


	// Left Click
	if (mPlayerInput.IsLeftClickPressed() && mGameWindow.hasFocus())
	{
		UseTool(worldMousePosition);
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
			mCurrentTool->UpdateCursor(worldMousePosition);
		}
	}
}

void cEditorManager::UseTool(sf::Vector2f& toolPosition)
{
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

