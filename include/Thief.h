#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Thief : public MovingObject
{
public:
	Thief(sf::Texture& image, float x, float y) : MovingObject(image, x, y), m_hasKey(false) {};
	using MovingObject::MovingObject;
	virtual sf::Sprite& initializeImg();
	void draw(sf::RenderWindow& window);
	virtual int move(sf::Time deltaTime, const char* NextStep);

private:
	bool m_hasKey;
};