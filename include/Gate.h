#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Gate : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite draw() {
		m_Gate.loadFromFile("Gate.jpg");
		return sf::Sprite(m_Gate);
	};

private:
	sf::Texture m_Gate;
};