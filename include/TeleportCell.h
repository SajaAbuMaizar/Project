#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class TeleportCell : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual sf::Sprite getImage() {
		m_TeleportCell.loadFromFile("TeleportCell.jpg");
		auto TeleportCellImg = sf::Sprite(m_TeleportCell);
		TeleportCellImg.scale(0.1f, 0.1f);
		return TeleportCellImg;
	};

private:
	sf::Texture m_TeleportCell;
};