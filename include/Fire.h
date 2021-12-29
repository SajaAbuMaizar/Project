#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticObject.h"

class Fire : public StaticObject
{
public:
	using StaticObject::StaticObject;
	//this function creates the image of the Fire Object and returns it
	virtual sf::Sprite initializeImg() {
		m_Fire.loadFromFile("Fire.png");
		m_FireImg = sf::Sprite(m_Fire);
		m_FireImg.scale(0.1f, 0.1f);
		m_FireImg.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
		return m_FireImg;
	};

	void draw(sf::RenderWindow window)
	{
		window.draw(initializeImg());
	}

private:
	sf::Texture m_Fire;
	sf::Sprite m_FireImg;
};