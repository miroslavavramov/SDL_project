#include "InputHandler.h"
#include "Game.h"
#include <iostream>

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler()
{
    // create button states for the mouse
    for(int i = 0; i < 4; i++)
    {
        m_mouseButtonStates.push_back(false);
        m_keyboardButtonStates.push_back(false);
    }
}

void InputHandler::clean()
{
}

void InputHandler::update()
{
    SDL_Event event;
    SDL_RendererFlip flipType = SDL_FLIP_NONE;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            Game::Instance()->quit();
        }
        
        if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_a)
            {
                m_keyboardButtonStates[K_LEFT] = true;
                flipType = SDL_FLIP_HORIZONTAL;
                
            }

            if(event.key.keysym.sym == SDLK_w)
            {
                m_keyboardButtonStates[K_UP] = true;
            }

            if(event.key.keysym.sym == SDLK_d)
            {
                m_keyboardButtonStates[K_RIGHT] = true;
            }
            if(event.key.keysym.sym == SDLK_s)
            {
                m_keyboardButtonStates[K_DOWN] = true;
            }
        }

        if(event.type == SDL_KEYUP)
        {
            if(event.key.keysym.sym == SDLK_a)
            {
                m_keyboardButtonStates[K_LEFT] = false;
            }

            if(event.key.keysym.sym == SDLK_w)
            {
                m_keyboardButtonStates[K_UP] = false;
            }

            if(event.key.keysym.sym == SDLK_d)
            {
                m_keyboardButtonStates[K_RIGHT] = false;
            }
            if(event.key.keysym.sym == SDLK_s)
            {
                m_keyboardButtonStates[K_DOWN] = false;
            }
        }

    }
}

void InputHandler::onKeyDown()
{
    m_keyStates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
    m_keyStates = SDL_GetKeyboardState(0);
}
