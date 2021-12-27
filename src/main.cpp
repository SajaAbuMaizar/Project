#include "Controller.h"

void setWindowDimentions(float& width, float& height);

int main()
{
	float width, height;

	setWindowDimentions(width, height);
	Controller game(width,height);
	game.operateGame();
	
	return 0;
}

void setWindowDimentions(float& width, float& height)
{
	// temp sf::Texture to optain the dimentions of the windows
	sf::Texture tempTex;
	tempTex.loadFromFile("Background.png");

	// width and height of window = width and height of background image
	width = tempTex.getSize().x;
	height = tempTex.getSize().y;
}