#pragma once

#include <SDL2/SDL.h>

class Cell
{
public:

    Cell() = default;

    explicit Cell(SDL_Renderer* renderer, int x, int y, int size);

    void draw();

    bool is_alive() const;

    void set_state(bool alive);

private:

    SDL_Renderer* renderer_;

    // Position and dimensions
    int x_;
    int y_;
    int size_;

    // Cell is alive or dead
    bool alive_;

    // "Area" of the cell
    SDL_Rect cell_rect_;
};
