#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Mage : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual sf::Sprite& initializeImg();
	void draw(sf::RenderWindow& window);
	virtual int move(sf::Time deltaTime, const char* NextStep);

private:

};