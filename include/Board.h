#pragma once
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <Wall.h>
#include <Gate.h>
#include <Orc.h>
#include <Chair.h>
#include <TeleportCell.h>
#include <Fire.h>
#include <King.h>
#include <Mage.h>
#include <Warrior.h>
#include <Thief.h>
#include <Key.h>
#include "MovingObject.h"

inline auto font1 = sf::Font();

class Board
{
public:
	Board();
	void readLevel(sf::Vector2u levelSize, int timer, sf::Clock clock,std::ifstream& board_file);

//private:
protected:
	std::vector<std::vector<std::unique_ptr<GameObject>>> m_board;
	std::vector<std::unique_ptr<MovingObject>> m_characters;
	std::vector<std::unique_ptr<MovingObject>> m_enemies;
	std::vector<std::unique_ptr<TeleportCell>> m_TeleportCells;
	sf::Vector2u m_levelSize;
	int m_timer;
	sf::Clock m_clock;
	sf::Clock m_moveClock;
	std::vector <sf::Texture> m_textures;
	sf::Vector2f kingPos;
	int m_player;
	bool m_thiefHasKey;
	bool m_success;
	// Helper Functions:
	void readChar(const char c, const size_t i, size_t& j);

};