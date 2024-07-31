#pragma once

#include <SDL2/SDL.h>

class Cell
{
public:

    Cell() = default;

    explicit Cell(int x, int y, int size);

    const SDL_Rect& get_cell_rect() const;

    bool is_alive() const;

    void set_state(bool alive);

private:

    int x_;
    int y_;
    int size_;

    bool alive_;

    SDL_Rect cell_rect_;
};
