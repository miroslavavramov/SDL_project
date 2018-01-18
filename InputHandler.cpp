#include "InputHandler.h"
#include "Game.h"
#include <iostream>

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler()
{
    // create button states for the mouse
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
}

void InputHandler::clean()
{
}

void InputHandler::update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            Game::Instance()->quit();
        }
        
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                m_mouseButtonStates[LEFT] = true;
            }

            if(event.button.button == SDL_BUTTON_MIDDLE)
            {
                m_mouseButtonStates[MIDDLE] = true;
            }

            if(event.button.button == SDL_BUTTON_RIGHT)
            {
                m_mouseButtonStates[RIGHT] = true;
            }
        }

        if(event.type == SDL_MOUSEBUTTONUP)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                m_mouseButtonStates[LEFT] = false;
            }

            if(event.button.button == SDL_BUTTON_MIDDLE)
            {
                m_mouseButtonStates[MIDDLE] = false;
            }

            if(event.button.button == SDL_BUTTON_RIGHT)
            {
                m_mouseButtonStates[RIGHT] = false;
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
