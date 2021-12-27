#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include"Help.h"

inline auto font = sf::Font();

class HomePage
{
public:
	HomePage(int width, int hight);
	std::vector <sf::Sprite> getHomeButtons() const;
	void initializeImage();
	bool handleButtonsClick(const sf::Vector2f& location);
	void ShowHelp();

private:
	std::vector <sf::Sprite> m_homeButtons;
	sf::Texture m_startGame;
	sf::Texture m_help;
	sf::Texture m_exitGame;
	sf::Text m_helpText;
	sf::Vector2f m_dimentions;
};