#pragma once

#include <SDL2/SDL.h>

class Cell
{
public:

    Cell() = default;

    explicit Cell(int x, int y, int size);

    const SDL_Rect& get_cell_rect() const;

private:

    int x_;
    int y_;
    int size_;

    bool alive_;

    SDL_Rect cell_rect_;
};
