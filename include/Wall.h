#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite draw() {
		m_Wall.loadFromFile("wall.jpg");
	    return sf::Sprite(m_Wall);
	};

private:
	sf::Texture m_Wall;
};