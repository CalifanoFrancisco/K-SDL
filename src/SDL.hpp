#ifndef SDL_KALIB_HPP 
#define SDL_KALIB_HPP

#include <SDL2/SDL.h>
#include <string>

// import this lib and import every other one
#include "Window.hpp"
#include "Context.hpp"

namespace sdl {

class SDL {
public:
    SDL() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            throw "SDL could not initialize\n" + std::string(SDL_GetError());
        }
    }
    
    ~SDL() {
        SDL_Quit();
    }
};

}

#endif