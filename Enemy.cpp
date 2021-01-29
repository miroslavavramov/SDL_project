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
    //m_position.setX(m_position.getX() +1);
    //m_position.setY(m_position.getY() +1);
    //m_y += 1;
    m_position.setX(m_position.getX());
    m_position.setX(m_position.getY());
    //std::cout << m_position.getX() << std::endl;
    //std::cout << m_position.getY() << std::endl;


    //m_iCurrentFrame = int(((SDL_GetTicks() /100) % 9));
}

float Enemy::getVelosityX()
{
   return m_velocity.getX();
}

float Enemy::getVelosityY()
{
   return m_velocity.getY();
}

void Enemy::clean()
{
}
