#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams):ObjectBehaviour(pParams)
{
    
}

void Player::draw()
{
    ObjectBehaviour::draw();
}

void Player::update()
{
    m_currentFrame = 256 * int(((SDL_GetTicks() / 100) % 6));
    m_acceleration.setX(0.0);
   /*
   if(InputHandler::Instance()->getMouseButtonState(LEFT))
   {
       m_velocity.setX(1.0);
   }

   if(InputHandler::Instance()->getMouseButtonState(RIGHT))
   {
       m_velocity.setX(-1.0);
   }*/

   if(InputHandler::Instance()->getKeyboardState(K_LEFT))
   {
       m_velocity.setX(-1.0);
       //std::cout << m_velocity.getX() << std::endl;
   }

   if(InputHandler::Instance()->getKeyboardState(K_RIGHT))
   {
       m_velocity.setX(1.0);
       //std::cout << m_velocity.getX() << std::endl;
   }

   if(InputHandler::Instance()->getKeyboardState(K_UP))
   {
       m_velocity.setY(-1.0);
       //std::cout << m_velocity.getY() << std::endl;
   }

   if(InputHandler::Instance()->getKeyboardState(K_DOWN))
   {
       m_velocity.setY(1.0);
       //std::cout << m_velocity.getY() << std::endl;
   }

   //std::cout << m_velocity.getX() << std::endl;
   //std::cout << m_velocity.getY() << std::endl;
   ObjectBehaviour::update();
   //m_position.setX(m_position.getX() -1);
   // m_x -= 1

}

float Player::getVelosityX()
{
   return m_velocity.getX();
}

float Player::getVelosityY()
{
   return m_velocity.getY();
}

void Player::clean()
{
}
