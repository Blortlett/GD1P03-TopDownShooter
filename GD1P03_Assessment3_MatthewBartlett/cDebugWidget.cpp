/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cDebugWidget]
Description : [cDebugWidget should be attatched to game objects with colliders. Collider should be passed in to the constructor of the debugWidget and this class will draw your collider out for you]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cDebugWidget.h"

cDebugWidget::cDebugWidget(cBoxCollider& boxCollider)
	: mBoxCollider(boxCollider)
{
	mColliderGraphic.setSize(boxCollider.GetBounds().size);
	mColliderGraphic.setPosition(boxCollider.GetPosition());
	mColliderGraphic.setOrigin(boxCollider.GetBounds().size / 2.0f);
	mColliderGraphic.setFillColor(sf::Color::Transparent);
	mColliderGraphic.setOutlineColor(sf::Color::Red);
	mColliderGraphic.setOutlineThickness(2);
}

cDebugWidget::cDebugWidget(cBoxCollider& boxCollider, sf::Color _Color)
	: mBoxCollider(boxCollider)
{
	mColliderGraphic.setSize(boxCollider.GetBounds().size);
	mColliderGraphic.setPosition(boxCollider.GetPosition());
	mColliderGraphic.setOrigin(boxCollider.GetBounds().size / 2.0f);
	mColliderGraphic.setFillColor(sf::Color::Transparent);
	mColliderGraphic.setOutlineColor(_Color);
	mColliderGraphic.setOutlineThickness(2);
}

cDebugWidget::~cDebugWidget()
{
}

void cDebugWidget::UpdateWidget()
{
	mColliderGraphic.setSize(mBoxCollider.GetBounds().size);
	mColliderGraphic.setPosition(mBoxCollider.GetPosition());
}

void cDebugWidget::DrawWidget(sf::RenderWindow& window)
{
	//if (!cApplicationManager::GetInstance().IsDebugModeActive()) return;
	UpdateWidget();
	window.draw(mColliderGraphic);
}
