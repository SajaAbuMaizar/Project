#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include"Help.h"

inline auto font = sf::Font();

class ToolBar
{
public:
	ToolBar();
	std::vector <sf::Sprite> getToolButtons() const;
	void initializeImage();
	bool handleToolsClick(const sf::Vector2f& location);
	void ShowHelp();

private:
	std::vector <sf::Sprite> m_toolButtons;
	sf::Texture m_startGame;
	sf::Texture m_help;
	sf::Texture m_exitGame;
	sf::Text m_helpText;
};