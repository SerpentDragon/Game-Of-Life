#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include "widgets/cell.h"
#include "widgets/button.h"
#include <SDL2/SDL_image.h>
#include "../controller/controller.h"
#include "texture_manager/texture_manager.h"

class Interface
{
public:

    Interface(int field_size);

    ~Interface();

    // Run the main loop of the game
    void run();

private:

    Interface(const Interface&) = delete;

    Interface(Interface&&) noexcept = delete;

    Interface& operator=(const Interface&) = delete;

    Interface& operator=(Interface&&) = delete;

private:

    // Init game window params
    void init_window();

    // Init texture manager to use textures
    void init_texture_manager();

    // Init widgets (game field & button)
    void init_widgets();

    // Display background
    void display_background();

    // Display game field
    void display_game_field();

    // Display button
    void display_button();

    // Process mouse press events
    void handle_mouse_event();

private:

    // Game window
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    std::shared_ptr<Controller> controller_;

    // Screen and Window params
    int screen_width_;
    int screen_height_;

    int window_width_;
    int window_height_;

    // Play/Pause button
    Button game_button_;

    // Game field & it's params
    std::vector<std::vector<Cell>> field_;
    int field_size_;
    int cell_size_;
    int left_top_x_;
    int left_top_y_;
};
