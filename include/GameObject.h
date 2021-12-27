#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(float x, float y) { m_position.x = x; m_position.y = y; };
	virtual sf::Sprite getImage() = 0;
	virtual ~GameObject() = default;

protected:
	sf::Vector2f m_position;
	int m_objectSizeFitter = 45;

};