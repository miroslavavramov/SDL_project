#ifndef __InputHandler__
#define __InputHandler__
#include <SDL2/SDL.h>
#include <stdint.h>
#include <vector>

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

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

    inline bool getMouseButtonState(int buttonNumber){ return m_mouseButtonStates[buttonNumber];}

private:
    InputHandler();
    ~InputHandler(){}
    
    std::vector<bool> m_mouseButtonStates;

    //handle kayboard ivents
    void onKeyDown();
    void onKeyUp();

    const Uint8* m_keyStates;
    static InputHandler* s_pInstance;
};
#endif
