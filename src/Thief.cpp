#include "Thief.h"

//This function creates the image of the Thief and initalizez it and returns it
sf::Sprite Thief::getImage()
{
	m_thief.loadFromFile("Thief.png");
	m_thiefImg = sf::Sprite(m_thief);
	m_thiefImg.scale(0.1f, 0.1f);
	m_thiefImg.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
	return m_thiefImg;
}