#include "cell.h"

Cell::Cell(SDL_Renderer* renderer, int x, int y, int size) : 
    Widget(renderer, x, y, size, size), alive_(false)
{
    
}

void Cell::draw() const
{
    alive_ ? 
        SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255) :
        SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);

    SDL_RenderFillRect(renderer_, &widget_rect_);

    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer_, &widget_rect_);
}

bool Cell::is_alive() const { return alive_; }

void Cell::set_state(bool alive) { alive_ = alive; }
