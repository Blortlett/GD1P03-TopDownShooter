#include "cApplicationManager.h"
#include "cAudioManager.h"

cApplicationManager::cApplicationManager()
    : mGameWindow(sf::VideoMode({ 1920, 1080 }), "Starline Miami ", sf::Style::None)
    , mGameManager(mGameWindow)
    , mMainMenu(mGameWindow, mGameManager.GetGameStateManager())
    , mCurrentState(EGameState::MainMenu) // Start in main menu
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

            switch (mCurrentState)
            {
                case EGameState::MainMenu:
                    mGameManager.RefreshDeltaTime(); // got to or else level 1 enemies break
                    cAudioManager::GetInstance().PlayMenuMusic();
                    // Handle Main Menu
                    mGameWindow.setView(mDefaultView);
                    mMainMenu.Update();
                    // Transition when Play is clicked
                    if (!mMainMenu.mIsActive)
                    {
                        mCurrentState = EGameState::Gameplay;
                    }
                    break;
                case EGameState::Gameplay:
                    cAudioManager::GetInstance().PlayLevelMusic();
                    // Game Tick runs all the gameplay
                    mGameManager.GameTick();
                    break;
            }
        // Clear last frame & display new frame
        mGameWindow.display();
    }
}
