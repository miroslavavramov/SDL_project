#ifndef __Enemy__
#define __Enemy__
#include "GameObject.h"
#include <iostream>
#include <string>

class Enemy : public GameObject
{
public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
   // void clean();
};
#endif /*Enemy*/
