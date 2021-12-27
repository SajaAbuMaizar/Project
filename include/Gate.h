#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Gate : public StaticObject
{
public:
	using StaticObject::StaticObject;
	//this function creates the image of the Gate Object and returns it
	virtual sf::Sprite getImage() {
		m_Gate.loadFromFile("Gate.png");
		m_GateImg = sf::Sprite(m_Gate);
		m_GateImg.scale(0.1f, 0.1f);
		m_GateImg.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
		return m_GateImg;
	};

private:
	sf::Texture m_Gate;
	sf::Sprite m_GateImg;
};