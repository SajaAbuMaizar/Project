#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Orc : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite getImage() {
		m_Orc.loadFromFile("Orc.png");
		auto OrcImg = sf::Sprite(m_Orc);
		OrcImg.scale(0.1f, 0.1f);
		return OrcImg;
	};

private:
	sf::Texture m_Orc;
};