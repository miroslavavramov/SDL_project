#ifndef __Enemy__
#define __Enemy__
#include <iostream>
#include <string>"
#include "ObjectBehaviour.h"

class Enemy : public ObjectBehaviour
{
public:
   Enemy(const LoaderParams* pParams);

   virtual void draw();
   virtual void update();
   virtual void clean();
};
#endif 
