#include "Warrior.h"

sf::Sprite Warrior::initializeImg() {
	m_image.setScale(0.1f, 0.1f);
	m_image.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
	return m_image;
};

void Warrior::draw(sf::RenderWindow& window)
{
	window.draw(initializeImg());
}