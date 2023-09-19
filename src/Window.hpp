#ifndef WINDOW_KALIB_HPP  
#define WINDOW_KALIB_HPP

#include <SDL2/SDL.h>   // SDL

namespace sdl 
{

class Window 
{
public:

    Window(
        const char* title, 
        const int x, 
        const int y, 
        const int width, 
        const int height
    ) 
    {
        m_window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        if (!m_window)
        {
            throw "Error creating window.\n";
        }
    }

    Window() 
    {
        m_window = SDL_CreateWindow("unnamed window", 0, 0, 100, 100, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    }

    ~Window() 
    {
        SDL_DestroyWindow(m_window);
    }

    void update()
    {
        SDL_GL_SwapWindow(m_window);
    }

    SDL_GLContext createContext()
    {
        return SDL_GL_CreateContext(m_window);
    }

    SDL_Window* getWindow() const 
    {
        return m_window;
    }

private:
    SDL_Window* m_window;
};

};



#endif