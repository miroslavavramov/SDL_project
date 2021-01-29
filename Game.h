#ifndef __Game__
#define __Game__
#include <vector>
#include <SDL2/SDL.h>
#include "GameObject.h"
#include "InputHandler.h"


class Game
{
public: 

    ~Game() {}
   static Game* Instance()
   {
        if(s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }

        return s_pInstance;
   }
   bool init(const char* title, int xpos, int ypos, int high, int width, int flags);
   void render();
   void clean();
   void update();
   void handleEvents();


   bool running() {return m_bRunning;}
   void quit() {m_bRunning = false;}
   SDL_Renderer* getRenderer() const{return g_pRenderer;}

private:
    Game() {}

    static Game* s_pInstance;

   //The window we'll be rendering to
   SDL_Window* m_pWindow;

   std::vector<GameObject*> m_gameObjects;
   //GameObject* m_player1;
   //GameObject* m_player2;
   //GameObject* m_player3;
   //GameObject* m_player4;

   GameObject* m_player;
   GameObject* m_enemy;
   GameObject* m_howl;
   GameObject* m_go;
 

   //SDL_Texture* m_pTexture;
   //SDL_Rect m_sourceRectangle;
   //SDL_Rect m_destinationRectangle;

   int m_currentFrame;

   //The surface contained by the window
   SDL_Renderer* g_pRenderer;

   bool m_bRunning;
};

#endif 
