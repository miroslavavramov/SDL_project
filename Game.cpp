#include "Game.h"
#include "Player.h"
#include "Enemy.h"

//libsdl-image1.2-dev\

Game* Game::s_pInstance = 0;
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

           if(g_pRenderer != 0) // renderer init success
           {
                cout << "renderer creation success\n";

                SDL_SetRenderDrawColor(g_pRenderer, 80, 93, 237, 255);
           }
           else
           {
                cout << "renderer init fail\n";
                return false; // renderer init fail
           }
        }
        else
        {
            printf("Windows could not be created! SDL_Error: %s\n", SDL_GetError());
            m_bRunning = false;
        }
    }

    LoaderParams* pParamsPlayer = new LoaderParams(200,200,250, 250,"girl");
    LoaderParams* pParamsEnemy = new LoaderParams(100,100,80, 60,"monkey");
    m_player = new Player(pParamsPlayer);
//    m_go = new GameObject();
    m_enemy = new Enemy(pParamsEnemy);

    m_bRunning = TextureManager::Instance()->Load("/home/default/projectGame/SDLproject/assets/monkey.png", "monkey", g_pRenderer);
    m_bRunning = TextureManager::Instance()->Load("/home/default/projectGame/SDLproject/assets/girl_spritestrip.png", "girl", g_pRenderer);
//    m_go->load(200,200,250, 250,"girl");
//    m_player->load(300,300,250, 250, "girl");
//    m_enemy->load(100,100,80, 60,"monkey");
//    m_gameObjects.push_back(m_go);

    m_gameObjects.push_back(m_player);
    m_gameObjects.push_back(m_enemy);

    return m_bRunning;

}

void Game::render()
{
    SDL_RenderClear(g_pRenderer);
    
    for(int i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
    SDL_RenderPresent(g_pRenderer);
}

void Game::update()
{
    for(std::vector<GameObject*>::size_type i = 0; i!= m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void Game::clean()
{
    
	SDL_DestroyWindow( m_pWindow );
    SDL_DestroyRenderer(g_pRenderer);
    SDL_Quit();
}

void Game::handleEvents()
{
    InputHandler::Instance()->update();
}
