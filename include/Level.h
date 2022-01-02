#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "Board.h"
#include "GameObject.h"



class Level
{
public:
	Level();
	void buildLevel();
	void levelOperator();

private:
	int m_level;
	sf::Clock m_clock;
	float m_timer;
	sf::Text m_time;
	std::string m_fileName;
	sf::Vector2u m_levelSize;
	// Helper Funvtions:
	std::string createFileName();
	void calculateLevelSize(std::ifstream& board_file);

};