#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>
#include <Wall.h>
#include <Gate.h>
#include <Orc.h>
#include <KingChair.h>
#include <TeleportCell.h>
#include <Fire.h>
#include <King.h>
#include <Mage.h>
#include <Warrior.h>
#include <Thief.h>
#include "MovingObject.h"

inline auto font1 = sf::Font();

class Board
{
public:
	Board();
	void readLevel(sf::Vector2u levelSize, int timer, sf::Clock clock,std::ifstream& board_file);
	void startLevel();
	//std::vector<std::vector<GameObject>> getBoard();
	void setObjectPosition(const size_t i, const size_t j);


private:
	std::vector<std::vector<std::unique_ptr<GameObject>>> m_board;
	sf::Vector2u m_levelSize;
	int m_timer;
	sf::Clock m_clock;
	sf::Clock m_moveClock;
	std::vector <sf::Texture> m_textures;
	sf::Vector2f kingPos;
	std::unique_ptr<MovingObject> m_player;
	// Helper Functions:
	void readChar(const char c, const size_t i, size_t& j);
	void convertClass(int i, int j);
	void convertClass2(sf::Vector2f pos1);
};