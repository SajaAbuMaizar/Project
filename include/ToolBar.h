#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class ToolBar
{
public:
	ToolBar();
	std::vector <sf::Sprite> getToolButtons();
	void initializeImage();

private:
	std::vector <sf::Sprite> m_toolButtons;
	sf::Texture m_startGame;
	sf::Texture m_help;
	sf::Texture m_exitGame;
};