#include "King.h"

//This function creates the image of the king and initalizez it and returns it
sf::Sprite King::getImage()
{
	m_King.loadFromFile("wall.jpg");
	m_KingImg = sf::Sprite(m_King);
	m_KingImg.scale(0.1f, 0.1f);
	m_KingImg.setPosition(45 * m_position.x, 45 * m_position.y);
	return m_KingImg;
}
