#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	using StaticObject::StaticObject;
	//this function creates the image of the Wall Object and returns it
	virtual sf::Sprite getImage() {
		m_Wall.loadFromFile("wall.jpg");
		m_wallImg = sf::Sprite(m_Wall);
		m_wallImg.scale(0.1f,0.1f);
		m_wallImg.setPosition(m_wallImg.getGlobalBounds().width*m_position.x, m_wallImg.getGlobalBounds().height * m_position.y);
	    return m_wallImg;
	};

private:
	sf::Texture m_Wall;
	sf::Sprite m_wallImg;
};