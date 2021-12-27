#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class TeleportCell : public StaticObject
{
public:
	using StaticObject::StaticObject;
	//this function creates the image of the Teleport Cell Object and returns it
	virtual sf::Sprite getImage() {
		m_TeleportCell.loadFromFile("TeleportCell.png");
		m_TeleportCellImg = sf::Sprite(m_TeleportCell);
		m_TeleportCellImg.scale(0.1f, 0.1f);
		m_TeleportCellImg.setPosition(m_objectSizeFitter * m_position.x, m_objectSizeFitter * m_position.y);
		return m_TeleportCellImg;
	};

private:
	sf::Texture m_TeleportCell;
	sf::Sprite m_TeleportCellImg;
};