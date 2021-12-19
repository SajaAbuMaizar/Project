#include "ToolBar.h"
#include <iostream>

const int WIDTH = 500;
const int HEIGHT = 500;
const int BUTTONS = 3;

ToolBar::ToolBar()
{
	m_startGame.loadFromFile("Start.png");
	auto startImg = sf::Sprite(m_startGame);
	m_toolButtons.push_back(startImg);

	m_help.loadFromFile("Help.png");
	auto helpImg = sf::Sprite(m_help);
	m_toolButtons.push_back(helpImg);

	m_exitGame.loadFromFile("Exit.png");
	auto exitImg = sf::Sprite(m_exitGame);
	m_toolButtons.push_back(exitImg);

	initializeImage();
}

void ToolBar::initializeImage()
{
	for (int counter = 0; counter < BUTTONS; counter++)
	{
		sf::Vector2f toolLoc(float(WIDTH / 2), float((HEIGHT / 6)*(counter+1)));
		sf::Vector2f toolScale(0.1f, 0.1f);
		m_toolButtons[counter].setOrigin(sf::Vector2f(m_toolButtons[counter].getTexture()->getSize() / 2u));
		m_toolButtons[counter].setPosition(toolLoc);
		m_toolButtons[counter].scale(toolScale);
	}
}

std::vector <sf::Sprite> ToolBar::getToolButtons()
{
	return m_toolButtons;
}