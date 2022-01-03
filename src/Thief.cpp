#include "Thief.h"

sf::Sprite Thief::initializeImg() {
	m_image.setScale(0.1f, 0.1f);
	if (m_firstDraw)
	{
		m_image.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
		m_firstDraw = false;
	}
	return m_image;
};

void Thief::draw(sf::RenderWindow& window)
{
	window.draw(initializeImg());
}

void Thief::move(sf::Time deltaTime, const char* NextStep)
{
	const auto speedPerSecond = 20.f;
	m_image.move(m_direction * speedPerSecond * deltaTime.asSeconds());
}