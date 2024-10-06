#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* myWindow = SDL_CreateWindow("colors",
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                            680,
                                            480,
                                            SDL_WINDOW_RESIZABLE
                                            );

    if(myWindow == NULL){
        cout<<"Error "<<SDL_GetError()<<" has been occured"<<endl;
        return 1;
    }

    SDL_Surface *screen = SDL_GetWindowSurface( myWindow );

    Uint32 grey = SDL_MapRGB( screen->format , 128, 128, 128 );

    SDL_FillRect( screen, NULL, grey );

    SDL_UpdateWindowSurface( myWindow );

    bool running = true;
    SDL_Event event;

    while( running ){
        while( SDL_PollEvent( &event) ){
            if( event.type == SDL_QUIT ){
                running = false;
                break;
            }
        }
    }

    SDL_DestroyWindow(myWindow);

    SDL_Quit();
    return 0;
}