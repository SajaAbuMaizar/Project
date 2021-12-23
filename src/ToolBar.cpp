#include "ToolBar.h"
#include <iostream>
#include <thread>

const int WIDTH = 1000;
const int HEIGHT = 600;
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

std::vector <sf::Sprite> ToolBar::getToolButtons() const
{
	return m_toolButtons;
}

void ToolBar::ShowHelp()
{
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	createHelp();
	sf::RenderWindow helpWindow(sf::VideoMode(WIDTH, HEIGHT), "Help");
    while (helpWindow.isOpen())
    {
		helpWindow.clear();
		helpWindow.draw(m_helpText);
		helpWindow.display();
        if (auto event = sf::Event{}; helpWindow.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: //if the user closes the window then close the window and exit
				helpWindow.close();
                break;
            }
        }
    }
}

void ToolBar::createHelp()
{
	m_helpText = sf::Text("Please enter the size of the window in the Terminal...\n", font);
	m_helpText.setCharacterSize(20);
}

bool ToolBar::handleToolsClick(const sf::Vector2f& location)
{
	for (int index = 0; index < BUTTONS; index++)
	{
		if (m_toolButtons[index].getGlobalBounds().contains(location))
		{
			switch (index)
			{
			case 0://if the user pressed the start button
				return true;
				break;
			case 1://if the user pressed the help button
				ShowHelp();
				break;
			case 2: //if the user pressed the exit button
				exit(0);
				break;
			}
		}
	}
	return false;
}