#pragma once

#include <memory>
#include <SDL2/SDL.h>
#include "../model/game_model.h"

class Controller
{
public:

    Controller();

    void set_game_model(std::shared_ptr<GameModel> game_model);

    // Processing cell press (i, j - indexes of the cell)
    void process_cell_pressed(int i, int j);

    // Processing of game button press
    void process_game_button_pressed();

    // Pause the game
    void pause_game();

    // Processing the app shutdown
    void process_exit();

    // Check whether the app is stopped
    bool is_stopped() const;

    // Check whether a game has started
    bool game_has_started() const;

    // Check whether the game is on
    bool is_run() const;

    bool game_over() const;

    void set_game_over();

private:

    std::shared_ptr<GameModel> game_model_;

    // Shutdown the app
    bool exit_;

    // Play or Pause
    bool run_;

    // Game has started or not
    bool game_started_;

    // Check whether the game is over
    bool game_over_;
};
