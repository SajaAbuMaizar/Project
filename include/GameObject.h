#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(float x, float y) { m_position.x = x; m_position.y = y; };
	virtual void draw() = 0;


private:
	sf::Vector2f m_position;

};