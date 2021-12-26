#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Fire : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite getImage() {
		m_Fire.loadFromFile("Fire.png");
		auto FireImg = sf::Sprite(m_Fire);
		FireImg.scale(0.1f, 0.1f);
		return FireImg;
	};

private:
	sf::Texture m_Fire;
};