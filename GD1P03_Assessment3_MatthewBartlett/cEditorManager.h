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

#pragma once
#include "cLevelManager.h"
#include "cPlayerInput.h"
// Draw Tool Includes
#include "cFullWallDrawTool.h"

class cEditorManager {
public:
    // Constructor
    cEditorManager(sf::RenderWindow& _GameWindow, cLevelManager& _LevelManager);
    // Tool Types
    enum class ToolType {
        ToolMode_FullWall,
        ToolMode_HalfWall,
    };
    void SetTool(ToolType type);

    // Usables
    void UseTool(sf::Vector2f& mousePos);
    void CompleteUseTool();

    // Updateables
    void UpdateCursor(sf::RenderWindow& window, sf::Vector2f mousePos);
    void DrawCursorToScreen(sf::RenderWindow& window);

private:
    cPlayerInput mPlayerInput;
    sf::RenderWindow& mGameWindow;

    // Current Tool Holder
    cBaseDrawTool* mCurrentTool;

    // Editor Tools
    cFullWallDrawTool mFullWallTool;

    // DrawGrid
    float mGridSize = 16.f;

    // Draw tool helpers
    bool mIsDrawing = false;
};