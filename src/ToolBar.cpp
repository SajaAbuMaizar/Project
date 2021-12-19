#include "ToolBar.h"

auto start = sf::Texture();
auto help = sf::Texture();
auto exitGame = sf::Texture();

ToolBar::ToolBar()
{
	start.loadFromFile("Start.png");
	auto startImg = sf::Sprite(start);
	help.loadFromFile("Help.png");
	auto helpImg = sf::Sprite(help);
	exitGame.loadFromFile("Exit.png");
	auto exitImg = sf::Sprite(exitGame);


}