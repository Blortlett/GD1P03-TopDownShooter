/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cApplicationManager]
Description : [This class handles displaying main menu or game states]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cApplicationManager.h"
#include "cAudioManager.h"
#include "cGameSettings.h"

cApplicationManager::cApplicationManager()
    : mGameWindow(sf::VideoMode({ 1920, 1080 }), "Starline Miami ", sf::Style::None)
    , mGameManager(mGameWindow)
    , mMainMenu(mGameWindow, mGameManager.GetGameStateManager())
    , mDefaultView(sf::FloatRect(sf::Vector2f(683.f, 500.f), { 1920.f, 1080.f }))
{
    mDefaultView.setSize(sf::Vector2f(1920.f, 1080.f));
    mDefaultView.setCenter(sf::Vector2f(683.f, 500.f));
}

cApplicationManager::~cApplicationManager()
{
}

void cApplicationManager::Run()
{
    while (mGameWindow.isOpen())
    {
        while (const std::optional event = mGameWindow.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                mGameWindow.close();
        }

        mGameWindow.clear();

            switch (cGameSettings::GetInstance().GetGameState())
            {
                case EGameState::MainMenu:
                    mGameManager.RefreshDeltaTime(); // got to or else level 1 enemies break
                    cAudioManager::GetInstance().PlayMenuMusic();
                    // Handle Main Menu
                    mGameWindow.setView(mDefaultView);
                    mMainMenu.Update();
                    break;
                case EGameState::Gameplay:
                    // Play level music
                    cAudioManager::GetInstance().PlayLevelMusic();
                    // Game Tick runs all the gameplay
                    mGameManager.GameTick();
                    break;
            }
        // Clear last frame & display new frame
        mGameWindow.display();
    }

    
}
