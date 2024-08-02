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

    Interface(std::shared_ptr<Controller> controller, int field_width, int field_height);

    ~Interface();

    // Run the main loop of the game
    void run();

    // Check whether the game is over (no alive cells) 
    // and display a new state of the field
    void update_field(field_data new_field);

    // Stop the game
    void stop();

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

    // Display all the components of the game window
    void display_game();

    // Display background
    void display_background();

    // Display game field
    void display_game_field();

    // Display button
    void display_button();

    // Display game over message
    void display_game_over();

    // Process mouse press events
    void handle_mouse_event();

private:

    // Game window
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    std::weak_ptr<Controller> controller_;

    // Screen and Window params
    int screen_width_;
    int screen_height_;

    int window_width_;
    int window_height_;

    // Play/Pause button
    Button game_button_;

    // Game field & it's params
    std::vector<std::vector<Cell>> field_;
    int field_width_;
    int field_height_;

    int cell_size_;
    int left_top_x_;
    int left_top_y_;
};
