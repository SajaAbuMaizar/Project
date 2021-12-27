#pragma once
#include <SFML/Graphics.hpp>
#include "HomePage.h"

class Controller {
public:
	Controller(int width, int height);
	void operateGame();
	

private:
	sf::RenderWindow m_window;
	HomePage m_home;
	int m_width;
	int m_height;
};