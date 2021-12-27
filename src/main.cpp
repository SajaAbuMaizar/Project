#include "Controller.h"


const int WIDTH = 1000; //to send the parameters
const int HEIGHT = 600;


int main()
{
	Controller game(WIDTH,HEIGHT);
	game.operateGame();
	
	return 0;
}
