#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

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

   SDL_Texture* m_pTexture;
   SDL_Rect m_sourceRectangle;
   SDL_Rect m_destinationRectangle;

   //The surface contained by the window
   SDL_Renderer* g_pRenderer;

   bool m_bRunning;
};

#endif /*defined(__Game__)*/
