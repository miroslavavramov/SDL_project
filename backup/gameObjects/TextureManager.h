#ifndef __TextureManager__
#define __TextureManager__

#include <iostream>
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>


using namespace std;

class TextureManager
{
public:
    bool Load(string filname, string id, SDL_Renderer* pRenderer);
    void Draw(string id, int x, int y, int with, int height, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);
    
    void DrawFrame(string id, int x, int y, int with, int height,int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);
    map<string, SDL_Texture*> m_textureMap;
    static TextureManager* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }

private:
    TextureManager(){};
    ~TextureManager(){};
    
    TextureManager(const TextureManager&);
    //TextureManager& operator=(const TextureManager&);

    static TextureManager* s_pInstance;
};

typedef TextureManager TextureManager;
#endif
