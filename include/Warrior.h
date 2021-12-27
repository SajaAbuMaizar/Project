#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Warrior : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual sf::Sprite getIWarrior() {
		m_Warrior.loadFromFile("wall.jpg");
		m_WarriorImg = sf::Sprite(m_Warrior);
		m_WarriorImg.scale(0.1f, 0.1f);
		m_WarriorImg.setPosition(45 * m_position.x, 45 * m_position.y);
		return m_WarriorImg;
	};

private:
	sf::Texture m_Warrior;
	sf::Sprite m_WarriorImg;
};