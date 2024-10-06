#ifndef SNAKE_H
#define SNAKE_H 

#include <iostream>

struct COORD
{
	int x;
	int y;
};

class Snake{
	public:
		Snake(int width,int height);
		void setPosition(COORD pos);
		COORD getPosition();
		int getPositionX();
		int getPositionY();
		void move();

	private:
		int pos_x;
		int pos_y;
};

#endif