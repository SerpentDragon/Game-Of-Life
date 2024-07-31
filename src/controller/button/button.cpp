#include "button.h"

Button::Button(SDL_Renderer* renderer, int x, int y, int width, int height) : 
    renderer_(renderer), x_(x), y_(y), width_(width), height_(height), 
    button_rect_({ x_, y_, width_, height_ })
{

}

void Button::draw() const
{
    
}

const SDL_Rect& Button::get_rect() const { return button_rect_; }
