#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class King : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual sf::Sprite getImage();

private:
	sf::Texture m_King;
	sf::Sprite m_KingImg;
};