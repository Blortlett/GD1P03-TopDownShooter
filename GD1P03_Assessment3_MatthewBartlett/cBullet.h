#pragma once
#include "cSharedUtils.h"

class cBullet
{
private:
	sf::Sprite mBulletSprite;
	sf::Vector2f mPosition;
	sf::Vector2f mMoveDirection;
	float const BULLET_MOVESPEED = 50.f;
public:
	cBullet();
	~cBullet() {}

	void Fire(sf::Vector2f _FirePosition, sf::Vector2f _AimPosition);
	void Move(float _DeltaTime);
	void Update(sf::RenderWindow& _Window, float _DeltaTime);
	void Draw(sf::RenderWindow& _Window) { _Window.draw(mBulletSprite); }
};