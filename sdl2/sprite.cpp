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

class Sprite{
    public:
        Sprite( Uint32 color, int x, int y, int w = 48, int h = 64 ){
            image = SDL_CreateRGBSurface( 0, w, h, 32, 0, 0, 0, 0 );
            SDL_FillRect( image, NULL, color);
            rect = image->clip_rect;

            origin_x = rect.w/2;
            origin_y = rect.h/2;

            rect.x = x - origin_x;
            rect.y = y - origin_y;
        }

        void update(){
            //can be overriden
        }

        void draw(SDL_Surface* destination){
            SDL_BlitSurface( image, NULL, destination, &rect);
        }

    private:
        SDL_Surface* image;
        SDL_Rect rect;

        int origin_x,origin_y;
};

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
    Uint32 black = SDL_MapRGB( screen->format, 0, 0, 0 );
	SDL_FillRect( screen, NULL, grey );

    Sprite object( black, window_width/2, window_height/2);
    object.draw( screen );

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