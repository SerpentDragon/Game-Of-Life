#include "button.h"

#include <iostream>

Button::Button(SDL_Renderer* renderer, int x, int y, int width, int height) : 
    renderer_(renderer), x_(x), y_(y), width_(width), height_(height), 
    button_rect_({ x_, y_, width_, height_ })
{
    texture_ = TextureManager::get_manager()->get_texture("button/green_play");
}

void Button::draw() const
{
    SDL_RenderCopy(renderer_, texture_, nullptr, &button_rect_);;
}

const SDL_Rect& Button::get_rect() const { return button_rect_; }
