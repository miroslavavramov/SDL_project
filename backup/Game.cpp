#include "Game.h"
//libsdl-image1.2-dev
bool Game::init(const char* title, int xpos, int ypos, int high, int width, int flags)
{
    m_bRunning = true;
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0 )
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        m_bRunning = false;
    }
    else
    {
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, high, width, flags);
        if(m_pWindow != 0)
        {
           g_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
        }
        else
        {
            printf("Windows could not be created! SDL_Error: %s\n", SDL_GetError());
            m_bRunning = false;
        }
    }
    
    SDL_Surface* pTempSurface = IMG_Load("/home/default/projectGame/SDLproject/assets/monkey.png");
    m_pTexture = SDL_CreateTextureFromSurface(g_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    //SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

    m_destinationRectangle.x = 0;
    m_sourceRectangle.x = 0;
    m_destinationRectangle.y = 0;
    m_sourceRectangle.y = 0;
    m_sourceRectangle.w = 80;
    m_sourceRectangle.h = 64;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;

    SDL_RenderCopy(g_pRenderer, m_pTexture, &m_sourceRectangle,
    &m_destinationRectangle);


    return m_bRunning;
}

void Game::render()
{
    SDL_SetRenderDrawColor(g_pRenderer, 80, 93, 237, 255);
    SDL_RenderClear(g_pRenderer);
    SDL_RenderCopyEx(g_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
    SDL_RenderPresent(g_pRenderer);
}

void Game::update()
{
    m_sourceRectangle.x = 80 * int(((SDL_GetTicks() / 100) % 9));
    //printf("x cordinate is %d", m_sourceRectangle);
    //SDL_Delay(15000);
    //m_bRunning = false;
}

void Game::clean()
{
    
	SDL_DestroyWindow( m_pWindow );
    SDL_DestroyRenderer(g_pRenderer);
    SDL_Quit();
}

