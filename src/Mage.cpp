#include "Mage.h"

//This function creates the image of the Mage and initalizez it and returns it
sf::Sprite Mage::getImage()
{
	m_mage.loadFromFile("Mage.png");
	m_mageImg = sf::Sprite(m_mage);
	m_mageImg.scale(0.1f, 0.1f);
	m_mageImg.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
	return m_mageImg;
}