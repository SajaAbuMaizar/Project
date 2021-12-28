#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Thief : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual sf::Sprite getImage();

private:
	sf::Texture m_thief;
	sf::Sprite m_thiefImg;
};