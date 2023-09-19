#ifndef CONTEXT_KALIBS_HPP
#define CONTEXT_KALIBS_HPP

#include <SDL2/SDL.h>
#include "Window.hpp"

namespace sdl
{

class Context {
public:
    Context(SDL_Window* window) 
    {
        m_glContext = SDL_GL_CreateContext(window);
    }

    Context(const Window& window) 
    {
        m_glContext = SDL_GL_CreateContext(window.getWindow());
    }

    ~Context() 
    {
        SDL_GL_DeleteContext(m_glContext);
    }

    SDL_GLContext getContext() const 
    {
        return m_glContext;
    }

private:
    SDL_GLContext m_glContext;
};

} // namespace sdl

#endif