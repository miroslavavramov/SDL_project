#include "Player.h"

Player::Player(const LoaderParams* pParams):ObjectBehaviour(pParams)
{
    
}

void Player::draw()
{
    ObjectBehaviour::draw();
}

void Player::update()
{
    m_acceleration.setX(1.0);
    ObjectBehaviour::update();
    //m_position.setX(m_position.getX() -1);
   // m_x -= 1;
}

void Player::clean()
{
}
