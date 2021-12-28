#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Mage : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual sf::Sprite getImage();

private:
	sf::Texture m_mage;
	sf::Sprite m_mageImg;
};