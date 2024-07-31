#include "cell.h"

Cell::Cell(SDL_Renderer* renderer, int x, int y, int size) 
    : renderer_(renderer), x_(x), y_(y), size_(size), alive_(false)
{
    cell_rect_ = { x, y, size, size };
}

void Cell::draw()
{
    alive_ ? 
        SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255) :
        SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);

    SDL_RenderFillRect(renderer_, &cell_rect_);

    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer_, &cell_rect_);
}

bool Cell::is_alive() const { return alive_; }

void Cell::set_state(bool alive) { alive_ = alive; }
