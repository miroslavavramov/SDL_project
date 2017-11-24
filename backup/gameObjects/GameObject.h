#ifndef __GameObject__
#define __GameObject__
#include "TextureManager.h"
#include <string>
//#include <SDL2/SDL>

class GameObject
{
public:
    virtual void load(int x, int y, int width, int height, std::string textureID);
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void update(/*int currentFrame*/);
    //virtual void clean();
protected:
    std::string m_sTextureID;
    int m_iCurrentFrame;
    int m_iCurrentRow;

    int m_x;
    int m_y;

    int m_width;
    int m_height;
};
#endif
