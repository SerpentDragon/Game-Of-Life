#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include "../view/cell.h"
#include <SDL2/SDL_image.h>

class Interface
{
public:

    Interface(int field_size);

    ~Interface();

    void run();

private:

    Interface(const Interface&) = delete;

    Interface(Interface&&) noexcept = delete;

    Interface& operator=(const Interface&) = delete;

    Interface& operator=(Interface&&) = delete;

    void init_window();

    void init_background();

    void init_game_field();

    void display_game_field();

private:

    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Texture* background_;

    int screen_width_;
    int screen_height_;

    int window_width_;
    int window_height_;

    std::vector<std::vector<Cell>> field_;
    int field_size_;
};
