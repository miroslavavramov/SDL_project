#ifndef __Player__
#define __Player__

#include <string>
#include "ObjectBehaviour.h"

class Player : public ObjectBehaviour 
{
public:

    Player(const LoaderParams* pParams);
    virtual float getVelosityX();
    virtual float getVelosityY();
    
    virtual void draw();
    virtual void update();
    virtual void clean();

};
#endif 
