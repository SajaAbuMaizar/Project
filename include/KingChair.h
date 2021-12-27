#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class KingChair : public StaticObject
{
public:
	using StaticObject::StaticObject;
	//this function creates the image of the King Chair Object and returns it
	virtual sf::Sprite getImage() {
		m_KingChair.loadFromFile("KingChair.png");
		m_KingChairImg = sf::Sprite(m_KingChair);
		m_KingChairImg.scale(0.1f, 0.1f);
		m_KingChairImg.setPosition(m_KingChairImg.getGlobalBounds().width * m_position.x, m_KingChairImg.getGlobalBounds().height * m_position.y);
		return m_KingChairImg;
	};

private:
	sf::Texture m_KingChair;
	sf::Sprite m_KingChairImg;
};