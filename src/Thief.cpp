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
	if (NextStep[6] == 'W' ||
		NextStep[6] == 'F' || NextStep[6] == 'O')  // 'K' = king chair
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