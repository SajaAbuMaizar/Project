#pragma once
#include "Board.h"

class BoardController : public Board
{
public:
	using Board::Board;
	void startLevel();
	void handleKeyPressed(sf::Keyboard::Key key);
	const char* getNextStep(sf::Time deltaTime, sf::Vector2f temp);
	void MoveEnemy(int enemyIndex);
	void handleArrowPressed(sf::Keyboard::Key key);

private:
	std::vector<sf::Clock> m_enemyClock;
};