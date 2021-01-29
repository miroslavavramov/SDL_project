#include "GameObject.h"
void GameObject::load(int x, int y, int width, int height, std::string textureID)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_sTextureID = textureID;

    m_iCurrentRow = 1;
    m_iCurrentFrame = 1;
}

void GameObject::draw(SDL_Renderer* pRenderer)
{
    TextureManager::Instance()->DrawFrame(m_sTextureID, m_x, m_y, m_width, m_height,
    m_iCurrentRow, m_iCurrentFrame, pRenderer);
    
}

void GameObject::update(/*int currentFrame*/)
{
//    m_x += 1;
//    m_iCurrentFrame = currentFrame;
}

