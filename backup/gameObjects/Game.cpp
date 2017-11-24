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
   /* 
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
*/

    //m_player1 = new Player();
    //m_player2 = new Player();
    //m_player3 = new Player();
    //m_player4 = new Player();
    
    //m_gameObjects.push_back(m_player1);
    //m_gameObjects.push_back(m_player2);
    //m_gameObjects.push_back(m_player3);
    //m_gameObjects.push_back(m_player4);
    
    m_player = new Player();
    m_go = new GameObject();
    m_enemy = new Enemy();

    m_bRunning = TextureManager::Instance()->Load("/home/default/projectGame/SDLproject/assets/monkey.png", "monkey", g_pRenderer);
    m_bRunning = TextureManager::Instance()->Load("/home/default/projectGame/SDLproject/assets/girl_spritestrip.png", "girl", g_pRenderer);
    m_go->load(200,200,250, 250,"girl");
    m_player->load(300,300,250, 250, "girl");
    m_enemy->load(100,100,80, 60,"monkey");
    m_gameObjects.push_back(m_go);
    m_gameObjects.push_back(m_player);
    m_gameObjects.push_back(m_enemy);

    return m_bRunning;

}

void Game::render()
{
    SDL_RenderClear(g_pRenderer);

//    TextureManager::Instance()->Draw("monkey",0, 0, 80, 64, g_pRenderer);

//    TextureManager::Instance()->DrawFrame("monkey", 100, 100, 80, 64, 1, m_currentFrame, g_pRenderer);

  //  m_player->draw(g_pRenderer);
    //m_gameObject->draw(g_pRenderer);

    //SDL_RenderCopyEx(g_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
    
    for(int i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw(g_pRenderer);
    }
    SDL_RenderPresent(g_pRenderer);
}

void Game::update()
{
    //m_currentFrame = 80 * int(((SDL_GetTicks() / 100) % 9));

//    m_player->update();
  //  m_gameObject->update(m_currentFrame);
    //printf("x cordinate is %d", m_sourceRectangle);
    //SDL_Delay(150);
    //m_bRunning = false;
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

