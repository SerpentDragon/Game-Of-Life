#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include "../view/cell.h"
#include "button/button.h"
#include <SDL2/SDL_image.h>
#include "texture_manager/texture_manager.h"

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

private:

    void init_window();

    void init_texture_manager();

    void init_game_field();

    void init_button();

    void display_game_field();

    void display_game_button();

    void handle_mouse_event();

private:

    // Game window
    SDL_Window* window_;
    SDL_Renderer* renderer_;

    // Play/Pause button
    Button game_button_;

    // Screen and Window params
    int screen_width_;
    int screen_height_;

    int window_width_;
    int window_height_;

    // Game field & it's params
    std::vector<std::vector<Cell>> field_;
    int field_size_;

    int cell_size_;
    int left_top_x_;
    int left_top_y_;
};
