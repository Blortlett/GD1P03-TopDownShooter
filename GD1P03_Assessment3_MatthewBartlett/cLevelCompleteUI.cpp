#include "cLevelCompleteUI.h"
#include "cSharedUtils.h"
#include "cLevelProgressTracker.h"

cLevelCompleteUI::cLevelCompleteUI(sf::RenderWindow& renderWindow)
	: mTitleText(cSharedUtils::GetInstance().mTitleFont, "LEVEL CLEARED", 14U)
	, mSubTitleText(cSharedUtils::GetInstance().mTitleFont, "PROCEED TO EXIT", 16U)
	, mRenderWindow(renderWindow)
	, mExitArrowUI(cSharedUtils::GetInstance().mUIArrow)
{
	// Set Title Text
	mTitleText.setFillColor(sf::Color(250, 0, 250, 0)); // Magenta color
	mTitleText.setCharacterSize(110U);
	mTitleText.setPosition(mTitlePosition);
	mTitleText.setOrigin(mTitleText.getGlobalBounds().size / 2.0f);
	// Set SubTitle Text
	mSubTitleText.setFillColor(sf::Color(250, 250, 250, 0)); // White Color
	mSubTitleText.setCharacterSize(80U);
	mSubTitleText.setPosition(mTitlePosition + sf::Vector2f(220.f, 130.f));
	mSubTitleText.setOrigin(mTitleText.getGlobalBounds().size / 2.0f);

	// Setup exit arrow UI to have center origin
	mExitArrowUI.setScale({2.f, 2.f});
	mExitArrowUI.setOrigin(mExitArrowUI.getGlobalBounds().size / 2.f);
}

void cLevelCompleteUI::Update(float _DeltaTime, sf::Vector2f _LevelExitPosition, sf::Vector2f _GameViewCenter)
{
	if (cLevelProgressTracker::GetInstance().CheckLevelComplete()) // CheckLevelComplete function is JANK
	{
		// -= Fade text in and out! =-
		// init scoped alpha float
		float FadeInAlpha;
		// Fade text in
		if (mFadeInTime <= mFadeInTimeMax)
		{
			// Tick up timer
			mFadeInTime += _DeltaTime;
			// Get alpha value
			FadeInAlpha = ((mFadeInTime / mFadeInTimeMax) * 255);
			// Assign Alpha value
			mTitleText.setFillColor(sf::Color(250, 0, 250, FadeInAlpha));
			mSubTitleText.setFillColor(sf::Color(250, 250, 250, FadeInAlpha));
		}
		// Let text hang on active
		else if (mActiveForTime >= 0.f)
		{
			// Tick down timer
			mActiveForTime -= _DeltaTime;
			// No need to do anything... just hang out here for a bit
		}
		else if (mFadeOutTime >= 0.f)
		{
			// Tick down timer
			mFadeOutTime -= _DeltaTime;
			// Get alpha value
			FadeInAlpha = ((mFadeOutTime / mFadeOutTimeMax) * 255);
			// Assign Alpha value
			mTitleText.setFillColor(sf::Color(250, 0, 250, FadeInAlpha));
			mSubTitleText.setFillColor(sf::Color(250, 250, 250, FadeInAlpha));
		}

		// -= Control level Exit Arrow =-			// Should be in its own class but yolo
		// Set arrow as visible if level complete
		mExitArrowUI.setColor(sf::Color::White);
		HandleExitArrowUI(_LevelExitPosition, _GameViewCenter);
	}
	else 
	{ // Level is complete but text already been displayed.. No need to repeat, just reset timers
		mFadeInTime = 0.f;
		mActiveForTime = mActiveForTimeMax;
		mFadeOutTime = mFadeOutTimeMax;
		// Set arrow to transparent if level not complete
		mExitArrowUI.setColor(sf::Color::Transparent);
		// Turn Text invisible if not display time
		mTitleText.setFillColor(sf::Color(250, 0, 250, 0));
		mSubTitleText.setFillColor(sf::Color(250, 250, 250, 0));
	}
}

void cLevelCompleteUI::Draw()
{
	// Draw Text
	mRenderWindow.draw(mTitleText);
	mRenderWindow.draw(mSubTitleText);
	// Draw arrow pointing to exit
	mRenderWindow.draw(mExitArrowUI);
}

void cLevelCompleteUI::HandleExitArrowUI(sf::Vector2f _LevelExitPosition, sf::Vector2f _GameViewCenter)
{
	// Get direction to exit
	sf::Vector2f DirectionToExit = _LevelExitPosition - _GameViewCenter;

	// Rotate arrow to point towards exit direction
	// Get rotation towards exit
	sf::Angle RotationToExit = sf::radians(std::atan2(DirectionToExit.y, DirectionToExit.x));
	// Set arrow's rotation
	mExitArrowUI.setRotation(RotationToExit);

	// Keep arrow within outer bounds of 1080x1920 window, but positioned in the direction of the exit
	// Get position on oval boundary
	float x = mOvalCenter.x + mOvalRadius.x * std::cos(RotationToExit.asRadians());
	float y = mOvalCenter.y + mOvalRadius.y * std::sin(RotationToExit.asRadians());
	// Set Arrows position around edges of screen
	mExitArrowUI.setPosition(sf::Vector2f(x, y));
}