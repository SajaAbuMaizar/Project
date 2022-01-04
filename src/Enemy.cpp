#include "Enemy.h"
#include <iostream>

sf::Sprite& Enemy::initializeImg() {
	m_image.setScale(0.1f, 0.1f);
	//m_image.setOrigin(sf::Vector2f(m_image.getTexture()->getSize() / 2u));
	if (m_firstDraw)
	{
		m_image.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
		m_firstDraw = false;
	}
	return m_image;
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(initializeImg());
}

int Enemy::move(sf::Time deltaTime, const char* NextStep)
{
	int moveStatus = 0;
	if (deltaTime.asSeconds() > 3.f)
	{
		sf::Clock temp;
		deltaTime = temp.getElapsedTime();
	}
	const auto speedPerSecond = 45.f;
	m_image.move(m_direction * speedPerSecond * deltaTime.asSeconds());
	return moveStatus;
}