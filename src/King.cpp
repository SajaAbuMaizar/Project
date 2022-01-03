#include "King.h"
#include <iostream>

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
	if (NextStep[6] == 'W' || NextStep[6] == 'F' ||
		NextStep[6] == 'O' || NextStep[6] == 'G')  // 'K' = king chair
	{
		return;
	}
	if (deltaTime.asSeconds() > 3.f)
	{
		sf::Clock temp;
		deltaTime = temp.getElapsedTime();
	}
	const auto speedPerSecond = 45.f;
	m_image.move(m_direction * speedPerSecond * deltaTime.asSeconds());
}