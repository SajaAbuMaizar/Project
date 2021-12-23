#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

#include "GameObject.h"



class Level
{
public:
	Level();
	void buildLevel();
	std::string createFileName();
	void levelOperator();
	void calculateLevelSize(std::ifstream& board_file);

private:
	int m_level;
	sf::Clock m_clock;
	float m_timer;
	std::string m_fileName;
	sf::Vector2u m_levelSize;
};