#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class TeleportCell : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite draw() {
		m_TeleportCell.loadFromFile("TeleportCell.jpg");
		return sf::Sprite(m_TeleportCell);
	};

private:
	sf::Texture m_TeleportCell;
};