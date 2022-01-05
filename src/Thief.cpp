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
	int moveStatus = S_CLEAR; // initialize move status: clear
	if (NextStep[6] == 'W' || NextStep[6] == 'F' || NextStep[6] == 'O' ||
		NextStep[6] == 'E'  || (NextStep[6] == 'G' && !m_hasKey))  // 'K' = king chair
		return S_BLOCKED; // update move status: blocked
	if (NextStep[6] == 'K')
	{
		moveStatus = S_KEY;
		m_hasKey = true;
	}
	if (NextStep[6] == 'G' && m_hasKey)
	{
		m_hasKey = false;
		moveStatus = S_GATE;// 4 = opened the gate
	}
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