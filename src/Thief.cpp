#include "Thief.h"

sf::Sprite& Thief::initializeImg() {
	m_image.setScale(0.1f, 0.1f);
	//m_image.setOrigin(sf::Vector2f(m_image.getTexture()->getSize() / 2u));
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

int Thief::move(sf::Time deltaTime, const char* NextStep)
{
	int moveStatus = 0;
	if (NextStep[6] == 'W' || NextStep[6] == 'F' || NextStep[6] == 'O' ||
		NextStep[6] == 'E'  || (NextStep[6] == 'G' && !m_hasKey))  // 'K' = king chair
		return -1;
	if (NextStep[6] == 'K')
	{
		moveStatus = 3;
		m_hasKey = true;
	}
	if (NextStep[6] == 'G' && m_hasKey)
	{
		m_hasKey = false;
		moveStatus = 4;// 4 = opened the gate
	}
	if (NextStep[6] == 'T')
		moveStatus = 6;
	if (NextStep[6] == 'e')
		moveStatus = 7;
	if (deltaTime.asSeconds() > 3.f)
	{
		sf::Clock temp;
		deltaTime = temp.getElapsedTime();
	}
	const auto speedPerSecond = 30.f;
	m_image.move(m_direction * speedPerSecond);
	return moveStatus;
}