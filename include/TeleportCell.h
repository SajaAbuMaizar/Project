#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class TeleportCell : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite getImage() {
		m_TeleportCell.loadFromFile("TeleportCell.jpg");
		m_TeleportCellImg = sf::Sprite(m_TeleportCell);
		m_TeleportCellImg.scale(0.1f, 0.1f);
		m_TeleportCellImg.setPosition(45 * m_position.x, 45 * m_position.y);
		return m_TeleportCellImg;
	};

private:
	sf::Texture m_TeleportCell;
	sf::Sprite m_TeleportCellImg;
};