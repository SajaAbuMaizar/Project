#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Orc : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite draw() {
		m_Orc.loadFromFile("Orc.jpg");
		return sf::Sprite(m_Orc);
	};

private:
	sf::Texture m_Orc;
};