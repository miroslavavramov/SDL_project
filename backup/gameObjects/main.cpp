#include "Game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Game *g_game = 0;

int main( int argc, char* args[] )
{

    g_game = new Game();
    
	//Initialize SDL
	g_game->init( "SDL from Miro", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    while(g_game->running())
    {
        g_game->render();
        g_game->update();

        SDL_Delay(10);
    }

    g_game->clean();

	return 0;
}
