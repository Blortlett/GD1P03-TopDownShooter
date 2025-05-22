#include "cBaseLevel.h"
#include "cDebugWidget.h"

cBaseLevel::cBaseLevel(sf::RenderWindow& _Window)
	: mRenderWindow(_Window)
{
}

cBaseLevel::~cBaseLevel()
{
    CleanupColliders();
    CleanupDebugWidgets();
}

void cBaseLevel::DebugDraw()
{
    // Draw all widgets for full wall colliders
    for (cDebugWidget* widget : mDebugGFXFullWall)
    {
        widget->DrawWidget(mRenderWindow);
    }

    // Draw all widgets for half wall colliders
    for (cDebugWidget* widget : mDebugGFXHalfWall)
    {
        widget->DrawWidget(mRenderWindow);
    }
}

void cBaseLevel::AddFullWallToList(cBoxCollider* _FullWall)
{
    // Add colider to vector list
	mFullWallColliders.push_back(_FullWall);
    cDebugWidget* DebugWidget = new cDebugWidget(*_FullWall); // Create Debug Widget
    // Add widget to widget list for drawing later
    mDebugGFXFullWall.push_back(DebugWidget);
}

void cBaseLevel::AddHalfWallToList(cBoxCollider* _HalfWall)
{
    // Add colider to vector list
	mHalfWallColliders.push_back(_HalfWall);
    cDebugWidget* DebugWidget = new cDebugWidget(*_HalfWall); // Create Debug Widget
    // Add widget to widget list for drawing later
    mDebugGFXHalfWall.push_back(DebugWidget);
}

void cBaseLevel::CleanupColliders()
{
    // Delete all full wall colliders
    for (cBoxCollider* collider : mFullWallColliders)
    {
        delete collider;
    }
    mFullWallColliders.clear();

    // Delete all half wall colliders
    for (cBoxCollider* collider : mHalfWallColliders)
    {
        delete collider;
    }
    mHalfWallColliders.clear();

    // Delete the background sprite
    delete mBackgroundSprite;
}

void cBaseLevel::CleanupDebugWidgets()
{
    // Delete all full wall debug widgets
    for (cDebugWidget* widget : mDebugGFXFullWall)
    {
        delete widget;
    }
    mDebugGFXFullWall.clear();

    // Delete all half wall debug widgets
    for (cDebugWidget* widget : mDebugGFXHalfWall)
    {
        delete widget;
    }
    mDebugGFXHalfWall.clear();
}
