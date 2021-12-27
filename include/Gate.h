#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Gate : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite getImage() {
		m_Gate.loadFromFile("Gate.jpg");
		m_GateImg = sf::Sprite(m_Gate);
		m_GateImg.scale(0.1f, 0.1f);
		m_GateImg.setPosition(45 * m_position.x, 45 * m_position.y);
		return m_GateImg;
	};

private:
	sf::Texture m_Gate;
	sf::Sprite m_GateImg;
};