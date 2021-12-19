#pragma once
#include <SFML/Graphics.hpp>
#include "ToolBar.h"

class Controller {
public:
	Controller(int width, int height);
	void operateGame();

private:
	sf::RenderWindow m_window;
	ToolBar m_tool;
	int m_width;
	int m_height;
};