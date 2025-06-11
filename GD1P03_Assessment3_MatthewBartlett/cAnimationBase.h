/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAnimation]
Description : [The cAnimation class is the base class all playable animations classes inherit from]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class cAnimationBase
{
public:
	// Constructor
	cAnimationBase(sf::Texture* _SpriteSheetTex);
	// Animate sprite
	virtual void Animate(sf::Vector2f _ObjectPosition, float _DeltaSeconds);
	// Send in false, function will return true on complete animation
	virtual void Animate(sf::Vector2f _ObjectPosition, float _DeltaSeconds, bool &_AnimationComplete);
	// Draw animation to window
	void Draw(sf::RenderWindow& _RenderWindow);
	// Rotate Animation
	void RotateAnimation(sf::Angle _Rotation);
	// Restart Animation
	void RestartAnimation();

	// Getters
	sf::Angle GetRotation();

	// Setters
	void SetPosition(sf::Vector2f _ObjectPosition) { mSprite.setPosition(_ObjectPosition); }

protected:
	// Time Variables
	float mAnimationTime = 0.f;
	float mFrameDuration;
	// Image Variables
	sf::Vector2u mCurrentFrame = sf::Vector2u(0, 0);
	sf::Vector2u mTotalFrames;
	sf::Vector2i mFrameSize;
	sf::Sprite mSprite;
	sf::IntRect mSpriteRect;
	// Variables to edit outside of class
	sf::Vector2f mScale;

	// Play till complete animtations:
	bool mIsAnimationComplete = false;
};