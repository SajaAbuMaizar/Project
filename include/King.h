#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class King : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual sf::Sprite getImage() {
		m_King.loadFromFile("wall.jpg");
		m_KingImg = sf::Sprite(m_King);
		m_KingImg.scale(0.1f, 0.1f);
		m_KingImg.setPosition(45 * m_position.x, 45 * m_position.y);
		return m_KingImg;
	};

private:
	sf::Texture m_King;
	sf::Sprite m_KingImg;
};