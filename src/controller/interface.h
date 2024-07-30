#pragma once

#include "settings.h"
#include <SDL2/SDL.h>

class Interface
{
public:

    Interface();

    ~Interface();

    void run();

private:

    Interface(const Interface&) = delete;

    Interface(Interface&&) noexcept = delete;

    Interface& operator=(const Interface&) = delete;

    Interface& operator=(Interface&&) = delete;

private:

    SDL_Window* window_;

    int screen_width_;
    int screen_height_;

};
