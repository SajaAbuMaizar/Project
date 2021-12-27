#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>
#include <Wall.h>
#include <Gate.h>
#include <Orc.h>
#include <KingChair.h>
#include <TeleportCell.h>
#include <Fire.h>

inline auto font1 = sf::Font();

class Board
{
public:
	Board(sf::Vector2u levelSize, int timer, sf::Clock clock) : 
		m_levelSize(levelSize), m_timer(timer), m_clock(clock){};
	void readLevel(std::ifstream& board_file);
	void startLevel();
	//std::vector<std::vector<GameObject>> getBoard();
	void setObjectPosition(const size_t i, const size_t j);


private:
	std::vector<std::vector<std::unique_ptr<GameObject>>> m_board;
	sf::Vector2u m_levelSize;
	int m_timer;
	sf::Clock m_clock;
	// Helper Functions:
	void readChar(const char c, const size_t i, size_t& j);

};