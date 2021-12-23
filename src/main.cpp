#include <iostream>
#include "Controller.h"
#include "StaticObject.h"

const int WIDTH = 500;
const int HEIGHT = 500;


int main()
{
	Controller gameControl(WIDTH,HEIGHT);
	gameControl.operateGame();
	
	return 0;
}
