#include "interface.h"

Interface::Interface()
{
    SDL_DisplayMode displayMode;
    if (SDL_GetCurrentDisplayMode(0, &displayMode) != 0)
    {
        screen_width_ = 0;
        screen_height_ = 0;
    }
    else
    {
        screen_width_ = displayMode.w;
        screen_height_ = displayMode.h;
    }

    window_ = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 3 * screen_width_ / 5, 4 * screen_height_ / 5, 
        SDL_WINDOW_SHOWN);
}

Interface::~Interface()
{
    SDL_DestroyWindow(window_);
}

void Interface::run()
{
    bool run = true;
    SDL_Event event;

    SDL_Surface* screen_surface = SDL_GetWindowSurface(window_);
    SDL_Surface* background = SDL_LoadBMP("img/background.bmp");

    while (run) 
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT) 
            {
                run = false;
            }
        }
        
        SDL_BlitSurface(background, nullptr, screen_surface, nullptr);

        SDL_UpdateWindowSurface(window_);
    }

    SDL_FreeSurface(screen_surface);
}
