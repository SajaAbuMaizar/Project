#include "King.h"

sf::Sprite King::initializeImg() {
	m_image.setScale(0.1f, 0.1f);
	if (m_firstDraw)
	{
		m_image.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
		m_firstDraw = false;
	}
	return m_image;
}

void King::draw(sf::RenderWindow& window)
{
	window.draw(initializeImg());
}

void King::move(sf::Time deltaTime, const char* NextStep)
{
	//if (NextStep == "class Wall")
	//{
	//	return;
//	}
	const auto speedPerSecond = 20.f;
	m_image.move(m_direction * speedPerSecond * deltaTime.asSeconds());
}