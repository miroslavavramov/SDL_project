#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams):ObjectBehaviour(pParams)
{
}

void Enemy::draw()
{
    ObjectBehaviour::draw();
}

void Enemy::update()
{
    m_position.setX(m_position.getX() +1);
    m_position.setY(m_position.getY() +1);
    //m_y += 1;


    //m_iCurrentFrame = int(((SDL_GetTicks() /100) % 9));
}

void Enemy::clean()
{
}
