#include "Game.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 900;

//Game *g_game = 0;

int main( int argc, char* args[] )
{

    
	//Initialize SDL
	if(Game::Instance()->init( "SDL from Miro", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN))
    {
        std::cout << "game init success!\n" << std::endl;  
        while(Game::Instance()->running())
        {
            Game::Instance()->handleEvents();
            Game::Instance()->render();
            Game::Instance()->update();

            SDL_Delay(10);
        }
    }
    else
    {
        std::cout << "Init finction feald" << SDL_GetError() <<std::endl;
        return -1;
    }
    
    std::cout << "game closing ..\n";
    Game::Instance()->clean();
    

	return 0;
}
