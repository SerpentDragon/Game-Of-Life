#pragma once

#include <memory>
#include <SDL2/SDL.h>
#include "../model/game_model.h"

class Controller
{
public:

    Controller(int field_size);

    // Processing cell press (i, j - indexes of the cell)
    void process_cell_pressed(int i, int j);

    // Processing of game button press
    void process_game_button_pressed();

    // Processing the app shutdown
    void process_exit();

    // Check whether the app is stopped
    bool is_stopped() const;

    // Check whether a game has started
    bool game_has_started() const;

private:

    std::unique_ptr<GameModel> game_model_;

    // Shutdown the app
    bool exit_;

    // Play or Pause
    bool run_;

    // Game has started or not
    bool game_started_;
};
