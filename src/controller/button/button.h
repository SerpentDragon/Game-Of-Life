#pragma once

#include <string>
#include <SDL2/SDL.h>

class Button
{
public:

    Button() = default;

    Button(SDL_Renderer* renderer, int x, int y, int width, int height);

    void draw() const;

    const SDL_Rect& get_rect() const;

private:

    // Renderer to draw the button
    SDL_Renderer* renderer_;

    // Button position and dimensions
    int x_;
    int y_;
    int width_;
    int height_;

    // "Area" of the button
    SDL_Rect button_rect_;
};
