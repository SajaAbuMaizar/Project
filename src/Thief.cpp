#include "Thief.h"

sf::Sprite Thief::initializeImg() {
	m_image.setScale(0.1f, 0.1f);
	m_image.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
	return m_image;
};

void Thief::draw(sf::RenderWindow& window)
{
	window.draw(initializeImg());
}