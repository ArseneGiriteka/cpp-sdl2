#ifndef  GAMELAUNCHER_H
#define GAMELAUNCHER_H

#include <iostream>
#include "snake.h"
#include "stdlib.h"
#include "time.h"

class GameLauncher{
	public:
		GameLauncher(int width, int height);
		void setUpGame(Snake* mSnake,int width, int height);
	private:


};

#endif