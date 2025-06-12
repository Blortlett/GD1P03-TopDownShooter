/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cCameraManager]
Description : [The cCameraManager class provides functionality to the player camera / sfml view]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cCameraManager.h"
#include "cPlayerCharacter.h"

cCameraManager::cCameraManager(cPlayerCharacter& _PlayerCharacter, sf::RenderWindow& _RenderWindow)
	: mPlayerCharacter(_PlayerCharacter)
    //                      init position //  View Size
    , mView(sf::FloatRect({ 200.f, 200.f }, { 1366, 768 }))
    , mRenderWindow(_RenderWindow)
{
	mView.setCenter(mPlayerCharacter.GetPosition());
    mView.zoom(0.5f);
}

void cCameraManager::Update(float _DeltaSeconds)
{
    // Move camera position toward player position
    sf::Vector2f currentCenter = mView.getCenter();
    sf::Vector2f targetCenter = mPlayerCharacter.GetPosition();
    sf::Vector2f newCenter = currentCenter + (targetCenter - currentCenter) * mFollowSpeed * _DeltaSeconds;

    // Update view position
    mView.setCenter(newCenter);
    mRenderWindow.setView(mView);
}
