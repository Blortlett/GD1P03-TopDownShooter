#pragma once
#include <SFML/Graphics.hpp>

class cLevelCompleteUI
{
private:
	// Render window
	sf::RenderWindow& mRenderWindow;
	sf::Vector2f const mWindowDimensions = sf::Vector2f(1920, 1080);

	// Oval Dimensions
	sf::Vector2f const mOvalCenter = { mWindowDimensions / 2.f };
	sf::Vector2f const mOvalRadius = { mOvalCenter.x - 50.f, mOvalCenter.y - 50.f };

	// -= Timers =-
	// Fade in timer
	float const mFadeInTimeMax = 1.f;
	float mFadeInTime = 0.f;
	// Active for timer
	float const mActiveForTimeMax = 3.f;
	float mActiveForTime = mActiveForTimeMax;
	// Fade out timer
	float const mFadeOutTimeMax = 1.f;
	float mFadeOutTime = mFadeOutTimeMax;

	// Title Text
	sf::Text mTitleText;
	sf::Text mSubTitleText;
	sf::Vector2f mTitlePosition = sf::Vector2f(1920 / 2, 180.f);

	// Arrow that points towards the level exit
	sf::Sprite mExitArrowUI;
	void HandleExitArrowUI(sf::Vector2f _LevelExitPosition, sf::Vector2f _GameViewCenter);
public:
	cLevelCompleteUI(sf::RenderWindow& renderWindow);

	void Update(float _DeltaTime, sf::Vector2f _LevelExitPosition, sf::Vector2f _GameViewCenter);
	void Draw();
};