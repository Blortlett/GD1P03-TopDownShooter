#include "cViewUI.h"
#include "cPlayerCharacter.h"
#include "cGameSettings.h"

cViewUI::cViewUI(sf::RenderWindow& _GameWindow, cPlayerCharacter& _PlayerCharacter, cGameStateManager& _GameStateManager)
	: mPlayerCharacter(_PlayerCharacter)
	, mGameWindow(_GameWindow)
	, mAmmoUI(_GameWindow)
	, mPauseMenuUI(_GameWindow)
	, mOptionsMenuUI(_GameWindow)
	, mDebugMenuUI(_GameWindow, _GameStateManager)
{
	// Set Size
	mUICanvas.setSize(sf::Vector2f(_GameWindow.getSize().x, _GameWindow.getSize().y));
	// Set Position to center screen
	mUICanvas.setCenter(sf::Vector2f(_GameWindow.getSize().x / 2.0f, _GameWindow.getSize().y / 2.0f));
	// Init ammo UI with player ammo count
	mAmmoUI.SetBulletCount(mPlayerCharacter.GetAmmoCount());
}

void cViewUI::Draw()
{
	// Set UI view
	mGameWindow.setView(mUICanvas);

	// Draw UI elements
	mAmmoUI.Draw();

	// Update & Draw pause menu UI
	mPauseMenuUI.Update(); 
	// Update & Draw options menu UI
	mOptionsMenuUI.Update();
	// Update & Draw Debug menu UI
	mDebugMenuUI.Update();
}

void cViewUI::Update()
{
	// Get ammo count from player
	int AmmoCount = mPlayerCharacter.GetAmmoCount();
	// Set UI Ammo count
	mAmmoUI.SetBulletCount(AmmoCount);
}
