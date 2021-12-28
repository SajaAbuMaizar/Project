#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"

class Warrior : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual sf::Sprite getImage();

private:
	sf::Texture m_warrior;
	sf::Sprite m_warriorImg;
};