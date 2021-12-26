#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Gate : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite getImage() {
		m_Gate.loadFromFile("Gate.jpg");
		auto GateImg = sf::Sprite(m_Gate);
		GateImg.scale(0.1f, 0.1f);
		return GateImg;
	};

private:
	sf::Texture m_Gate;
};