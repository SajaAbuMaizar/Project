#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Enemy : public MovingObject
{
public:
	using MovingObject::MovingObject;
	sf::Sprite& initializeImg();
	void draw(sf::RenderWindow& window);
	int move(sf::Time deltaTime, const char* NextStep);
	void setDirection(int key);
	~Enemy() = default;

private:

};