#include <iostream>
#include "Controller.h"


const int WIDTH = 1000;
const int HEIGHT = 600;


int main()
{
	Controller gameControl(WIDTH,HEIGHT);
	gameControl.operateGame();
	
	return 0;
}
