#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Mage : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual sf::Sprite getImage() {
		m_Mage.loadFromFile("wall.jpg");
		m_MageImg = sf::Sprite(m_Mage);
		m_MageImg.scale(0.1f, 0.1f);
		m_MageImg.setPosition(45 * m_position.x, 45 * m_position.y);
		return m_MageImg;
	};

private:
	sf::Texture m_Mage;
	sf::Sprite m_MageImg;
};