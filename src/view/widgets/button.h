#pragma once

#include <string>
#include "widget.h"
#include "../texture_manager/texture_manager.h"

class Button : public Widget
{
public:

    Button() = default;

    Button(SDL_Renderer* renderer, int x, int y, int width, int height);

    virtual ~Button() = default;

    // Draw the button
    void draw() const override;

    // Changes texture acording to the current state (play/pause)
    void on_button(int x, int y);

    // Check whether the button is pressed
    bool is_pressed(int x, int y);

private:

    // Pause or Play state of the button
    bool play_;

    // Texture to render
    SDL_Texture* texture_;
};
