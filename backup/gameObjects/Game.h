#ifndef __Game__
#define __Game__
#include <vector>
#include <SDL2/SDL.h>
#include "Player.h"
#include "Enemy.h"

class Game
{
public: 

    Game() {}
    ~Game() {}

   bool init(const char* title, int xpos, int ypos, int high, int width, int flags);
   void render();
   void clean();
   void update();

   bool running() {return m_bRunning;}

private:
   //The window we'll be rendering to
   SDL_Window* m_pWindow;

   std::vector<GameObject*> m_gameObjects;
   //GameObject* m_player1;
   //GameObject* m_player2;
   //GameObject* m_player3;
   //GameObject* m_player4;

   GameObject* m_player;
   GameObject* m_enemy;
   GameObject* m_go;
 

   //SDL_Texture* m_pTexture;
   //SDL_Rect m_sourceRectangle;
   //SDL_Rect m_destinationRectangle;

   int m_currentFrame;

   //The surface contained by the window
   SDL_Renderer* g_pRenderer;

   bool m_bRunning;
};

#endif /*defined(__Game__)*/
