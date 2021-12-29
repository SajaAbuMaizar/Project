#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include"Help.h"

inline auto font = sf::Font();

class HomePage
{
public:
	HomePage(int width, int hight);
	std::vector <sf::Sprite> getHomeButtons(int buttonPressed) const;
	void initializeImage();
	bool handleButtonsClick(const sf::Vector2f& location);
	int handleMouseMovedOnButtons(sf::Vector2f location);
	void ShowHelp();

private:
	std::vector <sf::Sprite> m_homeButtons;
	std::vector <sf::Sprite> m_homeButtons0;
	std::vector <sf::Sprite> m_homeButtons1;
	std::vector <sf::Sprite> m_homeButtons2;
	sf::Texture m_startGame;
	sf::Texture m_startGame2;
	sf::Texture m_help;
	sf::Texture m_help2;
	sf::Texture m_exitGame;
	sf::Texture m_exitGame2;
	sf::Text m_helpText;
	sf::Vector2f m_dimentions;
};