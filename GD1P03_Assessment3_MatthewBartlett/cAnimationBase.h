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
	cAnimationBase(sf::Sprite _SpriteSheet);
	void LoadSpriteSheet(std::string filePath);
	virtual void Animate(sf::Vector2f _ObjectPosition, float _DeltaSeconds) = 0;
	void Draw(sf::RenderWindow& renderWindow);
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
};