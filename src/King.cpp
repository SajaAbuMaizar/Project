#include "King.h"
#include <iostream>

sf::Sprite& King::initializeImg()
{
	m_image.setScale(0.1f, 0.1f);
	//m_image.setOrigin(sf::Vector2f(m_image.getTexture()->getSize() / 2u));
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

int King::move(sf::Time deltaTime, const char* NextStep)
{
	int moveStatus = S_CLEAR; // initial move status: clear way 
	if (NextStep[6] == 'W' || NextStep[6] == 'F' ||
		NextStep[6] == 'O' || NextStep[6] == 'G' || NextStep[6] == 'E')  // 'K' = king chair
		return S_BLOCKED; // update move status: blocked way
	if (NextStep[6] == 'C')
		moveStatus = S_CHAIR;
	if (NextStep[6] == 'T')
		moveStatus = S_TELE;
	if (NextStep[6] == 'e')
		moveStatus = S_KILL_PRESENT;
	if (deltaTime.asSeconds() > 3.f)
	{
		sf::Clock temp;
		deltaTime = temp.getElapsedTime();
	}
	const auto speedPerSecond = 30.f;
	m_image.move(m_direction * speedPerSecond);
	return moveStatus;
}