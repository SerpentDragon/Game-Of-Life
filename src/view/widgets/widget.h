#pragma once

#include <memory>
#include <SDL2/SDL.h>

class Widget
{
public:

    Widget() = default;

    Widget(SDL_Renderer* renderer, int x, int y, int width, int height);

    virtual void draw() const = 0;

protected:

    // This functions defines whether (x, y) is inside the widget area
    bool inside_widget(int x, int y) const;

protected:

    // Renderer to draw the widget
    SDL_Renderer* renderer_;

    // Position & size of the widget
    int x_;
    int y_;
    int width_;
    int height_;

    // "Area" of the widget
    SDL_Rect widget_rect_;
};
