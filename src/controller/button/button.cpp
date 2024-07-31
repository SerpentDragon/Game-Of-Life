#include "button.h"

#include <iostream>

Button::Button(SDL_Renderer* renderer, int x, int y, int width, int height) : 
    renderer_(renderer), x_(x), y_(y), width_(width), height_(height), 
    game_started_(false), play_(false), button_rect_({ x_, y_, width_, height_ })
{
    texture_ = TextureManager::get_manager()->get_texture("button/green_play");
}

void Button::draw() const
{
    SDL_RenderCopy(renderer_, texture_, nullptr, &button_rect_);;
}

void Button::on_button(int x, int y)
{
    if (inside_button(x, y))
    {
        if (play_)
        {
            texture_ = TextureManager::get_manager()->get_texture("button/blue_pause");
        }
        else
        {
            texture_ = TextureManager::get_manager()->get_texture("button/blue_play");
        }
    }
    else
    {
        if (play_)
        {
            texture_ = TextureManager::get_manager()->get_texture("button/green_pause");
        }
        else
        {
            texture_ = TextureManager::get_manager()->get_texture("button/green_play");
        }
    }
}

void Button::is_pressed(int x, int y)
{
    if (!inside_button(x, y)) return;

    if (!game_started_) game_started_ = true;

    play_ = !play_;
}

bool Button::game_is_on() const { return play_; }

bool Button::game_has_started() const { return game_started_; }

bool Button::inside_button(int x, int y) const
{
    return x_ <= x && x <= x_ + width_ && y_ <= y && y <= y_ + height_;
}