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
	, mHalfWallTool(_LevelManager)
	, mExitDoorDrawTool(_LevelManager)
	, mExitZoneDrawTool(_LevelManager)
	, mCameraView(_PlayerCameraView)
	, mLevelManager(_LevelManager)
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
	case cEditorManager::ToolType::ToolMode_ExitDoor:
		mCurrentTool = &mExitDoorDrawTool;
		break;
	case cEditorManager::ToolType::ToolMode_HalfWall:
		mCurrentTool = &mHalfWallTool;
		break;
	case cEditorManager::ToolType::ToolMode_ExitZone:
		mCurrentTool = &mExitZoneDrawTool;
		break;
	}
}

void cEditorManager::UpdateToolMode()
{
	if (mPlayerInput.IsFullWallKeyPressed())
	{ // Numpad 1
		SetTool(cEditorManager::ToolType::ToolMode_FullWall);
	}
	if (mPlayerInput.IsHalfWallKeyPressed())
	{ // Numpad 2
		SetTool(cEditorManager::ToolType::ToolMode_HalfWall);
	}
	if (mPlayerInput.IsExitDoorKeyPressed())
	{ // Numpad 3
		SetTool(cEditorManager::ToolType::ToolMode_ExitDoor);
	}
	if (mPlayerInput.IsExitZoneKeyPressed())
	{ // Numpad 4
		SetTool(cEditorManager::ToolType::ToolMode_ExitZone);
	}
}

void cEditorManager::UpdateCursor()
{
	// Get mouse world position
	sf::Vector2i mouseScreenPosition = sf::Mouse::getPosition(mGameWindow);
	sf::Vector2f worldMousePosition = mGameWindow.mapPixelToCoords(mouseScreenPosition, mCameraView);

	// Right Click to delete platform
	if (mPlayerInput.IsRightClickPressed() && mGameWindow.hasFocus())
	{
		mLevelManager.TryDeleteWall(worldMousePosition);
	}

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

