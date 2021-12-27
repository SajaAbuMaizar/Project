#include "HomePage.h"
#include <thread>
#include <iostream>

const int BUTTONS = 3;

enum Buttons{start, help, exitGame};

HomePage::HomePage(int width, int height)
{
	m_dimentions.x = float(width);
	m_dimentions.y = float(height);

	m_startGame.loadFromFile("Start Button.png");
	auto startImg = sf::Sprite(m_startGame);
	m_toolButtons.push_back(startImg);

	m_help.loadFromFile("Help Button.png");
	auto helpImg = sf::Sprite(m_help);
	m_toolButtons.push_back(helpImg);

	m_exitGame.loadFromFile("Exit Button.png");
	auto exitImg = sf::Sprite(m_exitGame);
	m_toolButtons.push_back(exitImg);

	initializeImage();
}

void HomePage::initializeImage()
{
	for (int counter = 0; counter < BUTTONS; counter++)
	{
		sf::Vector2f toolLoc(float(m_dimentions.x / 2), float((m_dimentions.y / 6)*(counter+1) + 200)); // +200 to print the buttons under the title "Save The King"
		sf::Vector2f toolScale(0.7f, 0.7f);
		m_toolButtons[counter].setOrigin(sf::Vector2f(m_toolButtons[counter].getTexture()->getSize() / 2u));
		m_toolButtons[counter].setPosition(toolLoc);
		m_toolButtons[counter].scale(toolScale);
	}
}

std::vector <sf::Sprite> HomePage::getToolButtons() const
{
	return m_toolButtons;
}
//	the function builds a Help object 
void HomePage::ShowHelp()
{
	Help help(m_dimentions.x, m_dimentions.y);
	help.showHelp();
}

bool HomePage::handleToolsClick(const sf::Vector2f& location)
{
	for (int index = 0; index < BUTTONS; index++)
	{
		if (m_toolButtons[index].getGlobalBounds().contains(location))
		{
			switch (index)
			{
			case start://if the user pressed the start button
				return true;
				break;
			case help://if the user pressed the help button
				ShowHelp();
				break;
			case exitGame: //if the user pressed the exit button
				exit(0);
				break;
			}
		}
	}
	return false;
}