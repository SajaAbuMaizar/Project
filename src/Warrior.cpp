#include "Warrior.h"

//This function creates the image of the Warrior and initalizez it and returns it
sf::Sprite Warrior::getImage()
{
	m_warrior.loadFromFile("wall.jpg");
	m_warriorImg = sf::Sprite(m_warrior);
	m_warriorImg.scale(0.1f, 0.1f);
	m_warriorImg.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
	return m_warriorImg;
}