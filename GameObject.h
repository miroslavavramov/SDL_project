#ifndef __GameObject__
#define __GameObject__
#include "TextureManager.h"
#include "LoaderParams.h"
#include <string>
//#include <SDL2/SDL>

class GameObject
{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    virtual float getVelosityX() = 0;
    virtual float getVelosityY() = 0;
protected:
    GameObject(const LoaderParams* pParams){}
    virtual ~GameObject(){}
};
#endif
