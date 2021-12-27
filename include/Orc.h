#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Orc : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite getImage() {
		m_Orc.loadFromFile("Orc.png");
		m_OrcImg = sf::Sprite(m_Orc);
		m_OrcImg.scale(0.1f, 0.1f);
		m_OrcImg.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
		return m_OrcImg;
	};

private:
	sf::Texture m_Orc;
	sf::Sprite m_OrcImg;
};