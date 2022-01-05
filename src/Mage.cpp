#include "Mage.h"

sf::Sprite& Mage::initializeImg() {
	m_image.setScale(0.1f, 0.1f);
	//m_image.setOrigin(sf::Vector2f(m_image.getTexture()->getSize() / 2u));
	if (m_firstDraw)
	{
		m_image.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
		m_firstDraw = false;
	}
	return m_image;
};

void Mage::draw(sf::RenderWindow& window)
{
	window.draw(initializeImg());
}

int Mage::move(sf::Time deltaTime, const char* NextStep)
{
	int moveStatus = S_CLEAR; // move status: clear
	if (NextStep[6] == 'W' || NextStep[6] == 'O' ||
		NextStep[6] == 'G' || NextStep[6] == 'E')  // 'K' = king chair
		return S_BLOCKED; // move status: blocked
	if (NextStep[6] == 'F')
		moveStatus = S_FIRE; //1 = move on fire
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