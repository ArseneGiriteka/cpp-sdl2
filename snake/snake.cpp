#include "snake.h"

using namespace  std;

Snake::Snake(int width, int height){
	this->pos_x = width;
	this->pos_y = height;
}

void Snake::setPosition(COORD pos){
	this->pos_x = pos.x;
	this->pos_y = pos.y;
}

COORD Snake::getPosition(){
	COORD position_coord;
	position_coord.x = this->pos_x;
	position_coord.y = this->pos_y;
	return position_coord;
}

int Snake::getPositionX(){
	return this->pos_x;
}

int Snake::getPositionY(){
	return this->pos_y;
}

void move(){
	
}