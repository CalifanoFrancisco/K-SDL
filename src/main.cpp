#include <SDL2/SDL.h>   // SDL
#include <GL/glew.h>    // openGL

#include <stdio.h>      // std

#include "Window.hpp"
#include "SDL.hpp"

#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

void initOpenGlSettings() 
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
}

void initGlew() 
{
    glewInit();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main() 
{
    // initiate sdl
    sdl::SDL();

    // create window
    sdl::Window window("Test screen", 0, 0, 800, 600);

    // opengl
    initOpenGlSettings();
    
    // create context
    sdl::Context context(window);
    
    // v-sync
    SDL_GL_SetSwapInterval(1);
    
    // glew
    initGlew();

    // main loop
    for (bool loop = true; loop; ) 
    {
        // events
        SDL_Event windowEvent;
        while (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {
                loop = false;
                break;
            }
        }

        //do drawing here

        window.update();
    }

    return 0;
}

int main2 ()
{
    
    // ----- Initialize SDL
    
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "SDL could not initialize\n");
        return 1;
    }

    // ----- Create window
    SDL_Window* window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_SIZE_X, SCREEN_SIZE_Y, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    
    if (!window)
    {
        fprintf(stderr, "Error creating window.\n");
        return 2;
    }

    // ----- SDL OpenGL settings
    initOpenGlSettings();

    // ----- SDL OpenGL context
    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    // ----- SDL v-sync
    SDL_GL_SetSwapInterval(1);

    // ----- GLEW
    initGlew();

    // ----- Game loop
    bool quit = false;
    while (quit == false)
    {
        SDL_Event windowEvent;
        while (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {
                quit = true;
                break;
            }
        }

        //do drawing here

        SDL_GL_SwapWindow(window);
    }

    // ----- Clean up
    SDL_GL_DeleteContext(glContext);

    
    //sdl::Window windowww("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_SIZE_X, SCREEN_SIZE_Y);

    return 0;
}

// SDL_Quit();
