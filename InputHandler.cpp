#include "InputHandler.h"
#include "Game.h"
#include <iostream>

InputHandler* InputHandler::s_pInstance = 0;

/*InputHandler::InputHandler()
{
    
}
*/
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
