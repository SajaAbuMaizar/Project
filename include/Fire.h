#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Fire : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite draw() {
		m_Fire.loadFromFile("Fire.png");
		return sf::Sprite(m_Fire);
	};

private:
	sf::Texture m_Fire;
};