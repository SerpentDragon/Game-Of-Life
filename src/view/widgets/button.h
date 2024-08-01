#pragma once

#include <string>
#include "widget.h"
#include "../texture_manager/texture_manager.h"

class Button : public Widget
{
public:

    Button() = default;

    Button(SDL_Renderer* renderer, int x, int y, int width, int height);

    // Draw the button
    void draw() const override;

    // Changes texture acording to the current state (play/pause)
    void on_button(int x, int y);

    // Check whether the button is pressed
    void is_pressed(int x, int y);

    // Check whether the game is on
    bool game_is_on() const;

    // Check whether the game has been started
    bool game_has_started() const;

private:

    bool game_started_;
    bool play_;

    SDL_Texture* texture_;
};
