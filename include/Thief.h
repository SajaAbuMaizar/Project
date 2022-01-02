#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Thief : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual sf::Sprite initializeImg();
	void draw(sf::RenderWindow& window);
	virtual void move(sf::Time deltaTime);

private:

};