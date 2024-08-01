#include "button.h"

Button::Button(SDL_Renderer* renderer, int x, int y, int width, int height)
    : Widget(renderer, x, y, width, height), game_started_(false), play_(false)
{
    texture_ = TextureManager::get_manager()->get_texture("button/green_play");
}

void Button::draw() const
{
    SDL_RenderCopy(renderer_, texture_, nullptr, &widget_rect_);
}

void Button::on_button(int x, int y)
{
    if (inside_widget(x, y))
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
    if (!inside_widget(x, y)) return;

    if (!game_started_) game_started_ = true;

    play_ = !play_;
}

bool Button::game_is_on() const { return play_; }

bool Button::game_has_started() const { return game_started_; }
