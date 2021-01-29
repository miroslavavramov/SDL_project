#include "ObjectBehaviour.h"
#include "Game.h"


ObjectBehaviour::ObjectBehaviour(const LoaderParams* pParams):GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0.0,0.0)
{
        m_width = pParams->getWidth();
        m_height = pParams->getHeight();
        m_textureID = pParams->getTextureID();

        m_currentRow = 1;
        m_currentFrame = 1;
}
void ObjectBehaviour::draw()
{
    if(m_velocity.getX() > 0)
        TextureManager::Instance()->DrawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_NONE);
    else
        TextureManager::Instance()->DrawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);

}

void ObjectBehaviour::update()
{
    m_velocity += m_acceleration;
    m_position += m_velocity;
}

void ObjectBehaviour::clean()
{

}
