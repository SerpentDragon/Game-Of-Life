#include "controller.h"

Controller::Controller() : exit_(false), run_(false), game_started_(false) {}

void Controller::process_init(int field_size)
{
    
}

void Controller::process_cell_pressed(int i, int j)
{

}

void Controller::process_game_button_pressed()
{
    if (!game_started_) game_started_ = true;

    run_ = !run_;
}

void Controller::process_exit() { exit_ = true; }

bool Controller::is_stopped() const { return exit_; }

bool Controller::game_has_started() const { return game_started_; }
