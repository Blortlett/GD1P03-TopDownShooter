#pragma once
#include <SFML/Graphics.hpp>
class iEntity {
public:
    virtual ~iEntity() {}
    virtual void Update(float _DeltaTime) = 0;
    virtual void Draw(sf::RenderWindow& _Window) = 0;
    virtual sf::FloatRect GetBounds() const = 0;
};