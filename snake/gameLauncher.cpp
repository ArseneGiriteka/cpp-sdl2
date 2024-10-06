#include "gameLauncher.h"

using namespace std;

GameLauncher::GameLauncher(int width,int height){
	int ixx = 0;
	srand(time(NULL));

	Snake* mySnake;

	bool gameIsOver = true;

	while(gameIsOver&&ixx<9000){
		
		this->setUpGame(mySnake,width,height);
		system("clear");
		ixx ++;
	}
	
}

void GameLauncher::setUpGame(Snake* mySnake,int width,int height){

	mySnake = new Snake ( (rand() % width-2)+1 , (rand() % height-2)+1 );

	for(int y = 0 ; y<height; y++){
		for(int x = 0; x<width; x++){
			if(y==0 || y==height-1 || x==0 || x==width-1){
				cout<<"#";
			}
			else if(y == mySnake->getPosition().y && x== mySnake->getPosition().x){
				cout<<"@";
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
}
