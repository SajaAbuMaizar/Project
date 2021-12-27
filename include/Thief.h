#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Thief : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual sf::Sprite getImage() {
		m_Thief.loadFromFile("wall.jpg");
		m_ThiefImg = sf::Sprite(m_Thief);
		m_ThiefImg.scale(0.1f, 0.1f);
		m_ThiefImg.setPosition(45 * m_position.x, 45 * m_position.y);
		return m_ThiefImg;
	};

private:
	sf::Texture m_Thief;
	sf::Sprite m_ThiefImg;
};