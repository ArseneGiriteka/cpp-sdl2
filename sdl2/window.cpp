#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("win32",
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                            640,
                                            480,
                                            SDL_WINDOW_OPENGL);

    if(window == NULL){
        cout<<"There was an error "<<SDL_GetError()<<endl;
    }
    SDL_Delay(9000);

    return 0;
}