#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

inline auto font1 = sf::Font();

class Level
{
public:
	Level();
	void buildLevel();
	void startLevel();
	std::string createFileName();
	void levelOperator();
	void calculateLevelSize(std::ifstream& board_file);
	void readLevel(std::ifstream& board_file);

private:
	int m_level;
	sf::Clock m_clock;
	float m_timer;
	std::string m_fileName;
	//std::vector<std::vector<>>
	sf::Vector2u m_levelSize;
};