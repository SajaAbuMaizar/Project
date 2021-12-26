#include <iostream>
#include "Controller.h"


const int WIDTH = 1000; //to send the parameters
const int HEIGHT = 600;


int main()
{
	Controller gameControl(WIDTH,HEIGHT);
	gameControl.operateGame();
	
	return 0;
}
