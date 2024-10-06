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
                                            SDL_WINDOW_RESIZABLE);

    if(window == NULL){
        cout<<"There was an error "<<SDL_GetError;
        return 1;
    }

    SDL_Event event;
    bool running = true;

    while(running){
        
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = false;
                break;
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}