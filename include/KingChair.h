#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class KingChair : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite draw() {
		m_KingChair.loadFromFile("KingChair.png");
		return sf::Sprite(m_KingChair);
	};

private:
	sf::Texture m_KingChair;
};