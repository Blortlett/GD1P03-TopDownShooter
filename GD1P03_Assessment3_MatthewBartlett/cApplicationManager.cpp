#include "cApplicationManager.h"

cApplicationManager::cApplicationManager()
    : mGameWindow(sf::VideoMode({ 1920, 1080 }), "Starline Whammy ", sf::Style::None)
    , mGameManager(mGameWindow)
{

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
            // Optional: Add escape key to exit fullscreen
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                mGameWindow.close();
        }

        mGameWindow.clear();
        
        // Game Tick runs all the gameplay
        mGameManager.GameTick();

        mGameWindow.display();
    }
}
