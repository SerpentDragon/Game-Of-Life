#include "cell.h"

Cell::Cell(int x, int y, int size) : x_(x), y_(y), size_(size), 
    alive_(false)
{
    cell_rect_ = { x, y, size, size };
}

const SDL_Rect& Cell::get_cell_rect() const { return cell_rect_; }

bool Cell::is_alive() const { return alive_; }

void Cell::set_state(bool alive) { alive_ = alive; }
