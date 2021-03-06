#pragma once
#include "Board.h"
#include "levelData.h"

class BoardController : public Board
{
public:
	using Board::Board;
	bool startLevel(int levelNum, bool timeLimitedLevel);
	void handleKeyPressed(sf::Keyboard::Key key);
	const char* getNextStep(sf::Time deltaTime, sf::Vector2f temp);
	void MoveEnemy(int enemyIndex);
	void handleArrowPressed(sf::Keyboard::Key key);

private:
	std::vector<sf::Clock> m_enemyClock;
	int m_TimeLeft;
};