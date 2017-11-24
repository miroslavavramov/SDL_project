#ifndef __InputHandler__
#define __InputHandler__
#include <SDL2/SDL.h>
#include <stdint.h>


class InputHandler
{
public:

    static InputHandler* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
            return s_pInstance;
        }

        return s_pInstance;
    }

    void update();
    void clean();
    //SDL_GetKeyboardState(int numkeys);

private:
    InputHandler(){}
    ~InputHandler(){}
    
    //handle kayboard ivents
    void onKeyDown();
    void onKeyUp();

    const Uint8* m_keyStates;
    static InputHandler* s_pInstance;
};
#endif
