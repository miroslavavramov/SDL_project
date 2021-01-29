#ifndef __ObjectBehaviuor__
#define __ObjectBehaviuor__
#include "GameObject.h"
#include "Vector2D.h"

class ObjectBehaviour : public GameObject
{
public:
    ObjectBehaviour(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

protected:
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;
    int m_width;
    int m_height;
    int m_currentRow;
    int m_currentFrame;
    std::string m_textureID;


};

#endif

