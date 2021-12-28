#include "King.h"

//This function creates the image of the king and initalizez it and returns it
sf::Sprite King::getImage()
{
	m_King.loadFromFile("wall.jpg");
	m_KingImg = sf::Sprite(m_King);
	m_KingImg.scale(0.1f, 0.1f);
	m_KingImg.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
	return m_KingImg;
}
