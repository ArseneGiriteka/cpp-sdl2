#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main(int argc,char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* myWindow = SDL_CreateWindow("mywindow",
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                            680,
                                            580,
                                            SDL_WINDOW_RESIZABLE);

    if(myWindow == NULL){
        cout<<"Oops ,error : "<<SDL_GetError()<<endl;
        return 1;
    }

    bool running = true;
    SDL_Event event;

    int x,y,w,h;

    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = false;
                break;
            }
        }
        SDL_GetWindowPosition(myWindow, &x, &y);

        SDL_SetWindowTitle(myWindow, "Saru");

        cout<<"("<<x<<","<<y<<")"<<endl;

    }

    SDL_DestroyWindow(myWindow);

    SDL_Quit();
    return 0;
}