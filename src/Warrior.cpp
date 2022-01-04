#include "Warrior.h"
#include <iostream>

sf::Sprite& Warrior::initializeImg() {
	m_image.setScale(0.1f, 0.1f);
	//m_image.setOrigin(sf::Vector2f(m_image.getTexture()->getSize() / 2u));
	if (m_firstDraw)
	{
		m_image.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
		m_firstDraw = false;
	}
	return m_image;
};

void Warrior::draw(sf::RenderWindow& window)
{
	window.draw(initializeImg());
}

int Warrior::move(sf::Time deltaTime, const char* NextStep)
{
	int moveStatus = 0;
	if (NextStep[6] == 'W' || NextStep[6] == 'F' ||
		NextStep[6] == 'G' || NextStep[6] == 'E')  // 'K' = king chair
		return -1;
	if (NextStep[6] == 'O')
		moveStatus = 2; // 2 = moved on orc and put key instead
	if (NextStep[6] == 'T')
		moveStatus = 6;
	if (deltaTime.asSeconds() > 3.f)
	{
		sf::Clock temp;
		deltaTime = temp.getElapsedTime();
	}
	const auto speedPerSecond = 45.f;
	m_image.move(m_direction * speedPerSecond * deltaTime.asSeconds());
	return moveStatus;
}