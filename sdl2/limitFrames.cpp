#include <SDL2/SDL.h>
#include <iostream>

#define fps 60

#define window_width 600
#define window_height 400

using namespace std;

void capFrameRate( Uint32 starting_ticks){
	if((1000/fps) > (SDL_GetTicks() - starting_ticks)){
    	SDL_Delay( (1000/fps) - ( SDL_GetTicks() - starting_ticks ) );
    }
}

int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* myWindow = SDL_CreateWindow("colors",
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                            window_width,
                                            window_height,
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

	Uint32 starting_ticks;

    bool running = true;
    SDL_Event event;

    while( running ){
    	starting_ticks = SDL_GetTicks();

        while( SDL_PollEvent( &event) ){


            if( event.type == SDL_QUIT ){
                running = false;
                break;
            }
        }
        capFrameRate(starting_ticks);

    }

    SDL_DestroyWindow(myWindow);

    SDL_Quit();
    return 0;
}