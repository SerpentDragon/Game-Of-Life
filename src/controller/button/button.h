#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "../texture_manager/texture_manager.h"

class Button
{
public:

    Button() = default;

    Button(SDL_Renderer* renderer, int x, int y, int width, int height);

    // Draw the button
    void draw() const;

    // Changes texture acording to the current state (play/pause)
    void on_button(int x, int y);

    // Check whether the button is pressed
    void is_pressed(int x, int y);

    // Check whether the game is on
    bool game_is_on() const;

    // Check whether the game has been started
    bool game_has_started() const;

private:

    // This functions defines whether (x, y) is inside the button area
    bool inside_button(int x, int y) const;

private:

    // Renderer to draw the button
    SDL_Renderer* renderer_;

    // Button position and dimensions
    int x_;
    int y_;
    int width_;
    int height_;

    bool game_started_;
    bool play_;

    // "Area" of the button
    SDL_Rect button_rect_;

    SDL_Texture* texture_;
};
