#include "HomePage.h"
#include <thread>

enum CONSTS { BUTTONS = 3 };

enum Buttons { START_GAME, SHOW_HELP, EXIT_GAME };

//The c-tor of HomePage sets the width and height of the window of the HomePage
//and creates the buttons that are shown on the screen
HomePage::HomePage(int width, int height)
{
	m_dimentions.x = float(width);
	m_dimentions.y = float(height);

	//vector = 3
	m_startGame.loadFromFile("Start Button.png");
	auto startImg = sf::Sprite(m_startGame);
	m_homeButtons.push_back(startImg);

	m_help.loadFromFile("Help Button.png");
	auto helpImg = sf::Sprite(m_help);
	m_homeButtons.push_back(helpImg);

	m_exitGame.loadFromFile("Exit Button.png");
	auto exitImg = sf::Sprite(m_exitGame);
	m_homeButtons.push_back(exitImg);


	m_startGame2.loadFromFile("Start Button Clicked.png");
	auto startImg2 = sf::Sprite(m_startGame2);

	m_help2.loadFromFile("Help Button Clicked.png");
	auto helpImg2 = sf::Sprite(m_help2);

	m_exitGame2.loadFromFile("Exit Button Clicked.png");
	auto exitImg2 = sf::Sprite(m_exitGame2);

	//vector = 0
	m_homeButtons0.push_back(startImg2);
	m_homeButtons0.push_back(helpImg);
	m_homeButtons0.push_back(exitImg);

	//vectror = 1
	m_homeButtons1.push_back(startImg);
	m_homeButtons1.push_back(helpImg2);
	m_homeButtons1.push_back(exitImg);

	//vectror = 2
	m_homeButtons2.push_back(startImg);
	m_homeButtons2.push_back(helpImg);
	m_homeButtons2.push_back(exitImg2);


	initializeImage();
}

//this function initialize the images of the button
void HomePage::initializeImage()
{
	for (int counter = 0; counter < BUTTONS; counter++)
	{
		sf::Vector2f toolLoc(float(m_dimentions.x / 2), float((m_dimentions.y / 6) * (counter + 1) + 200)); // +200 to print the buttons under the title "Save The King"
		sf::Vector2f toolScale(0.7f, 0.7f);
		m_homeButtons[counter].setOrigin(sf::Vector2f(m_homeButtons[counter].getTexture()->getSize() / 2u));
		m_homeButtons[counter].setPosition(toolLoc);
		m_homeButtons[counter].scale(toolScale);
	}
	for (int counter = 0; counter < BUTTONS; counter++)
	{
		sf::Vector2f toolLoc(float(m_dimentions.x / 2), float((m_dimentions.y / 6) * (counter + 1) + 200)); // +200 to print the buttons under the title "Save The King"
		sf::Vector2f toolScale(0.7f, 0.7f);
		m_homeButtons0[counter].setOrigin(sf::Vector2f(m_homeButtons0[counter].getTexture()->getSize() / 2u));
		m_homeButtons0[counter].setPosition(toolLoc);
		m_homeButtons0[counter].scale(toolScale);
	}
	for (int counter = 0; counter < BUTTONS; counter++)
	{
		sf::Vector2f toolLoc(float(m_dimentions.x / 2), float((m_dimentions.y / 6) * (counter + 1) + 200)); // +200 to print the buttons under the title "Save The King"
		sf::Vector2f toolScale(0.7f, 0.7f);
		m_homeButtons1[counter].setOrigin(sf::Vector2f(m_homeButtons1[counter].getTexture()->getSize() / 2u));
		m_homeButtons1[counter].setPosition(toolLoc);
		m_homeButtons1[counter].scale(toolScale);
	}
	for (int counter = 0; counter < BUTTONS; counter++)
	{
		sf::Vector2f toolLoc(float(m_dimentions.x / 2), float((m_dimentions.y / 6) * (counter + 1) + 200)); // +200 to print the buttons under the title "Save The King"
		sf::Vector2f toolScale(0.7f, 0.7f);
		m_homeButtons2[counter].setOrigin(sf::Vector2f(m_homeButtons2[counter].getTexture()->getSize() / 2u));
		m_homeButtons2[counter].setPosition(toolLoc);
		m_homeButtons2[counter].scale(toolScale);
	}

}

std::vector <sf::Sprite> HomePage::getHomeButtons(int buttonPressed) const
{

	switch (buttonPressed)
	{
	case START_GAME://if the user pressed the start button
		return m_homeButtons0; //
	case SHOW_HELP://if the user pressed the help button
		return m_homeButtons1; //
	case EXIT_GAME: //if the user pressed the exit button
		return m_homeButtons2;
	}
	return m_homeButtons;
}

// the function builds a Help object 
void HomePage::ShowHelp()
{
	Help help((int)m_dimentions.x, (int)m_dimentions.y);
	help.showHelp();
}

//this function handles the click on the buttons of the menu in the HomePage
bool HomePage::handleButtonsClick(const sf::Vector2f& location)
{
	for (int index = 0; index < BUTTONS; index++)
	{
		if (m_homeButtons[index].getGlobalBounds().contains(location))
		{
			switch (index)
			{
			case START_GAME://if the user pressed the start button
				return true;
			case SHOW_HELP://if the user pressed the help button
				ShowHelp();
				break;
			case EXIT_GAME: //if the user pressed the exit button
				exit(0);
			}
		}
	}
	return false;
}

int HomePage::handleMouseMovedOnButtons(sf::Vector2f location)
{
	for (int index = 0; index < BUTTONS; index++)
	{
		if (m_homeButtons[index].getGlobalBounds().contains(location))
		{
			switch (index)
			{
			case START_GAME://if the user pressed the start button
				return START_GAME;
			case SHOW_HELP://if the user pressed the help button
				return SHOW_HELP;
			case EXIT_GAME: //if the user pressed the exit button
				return EXIT_GAME;
			}
		}
	}
	return 3; //3 = case of not moving on buttons, change to enum
}