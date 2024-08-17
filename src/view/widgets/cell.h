#pragma once

#include "widget.h"

class Cell : public Widget
{
public:

    Cell() = default;

    explicit Cell(SDL_Renderer* renderer, int x, int y, int size);

    virtual ~Cell() = default;

    // Draw the cell
    void draw() const override;

    // Check ewhether the cell is alive
    bool is_alive() const;

    // Set current state of the cell
    void set_state(bool alive);

private:

    // Cell is alive or dead
    bool alive_;
};
