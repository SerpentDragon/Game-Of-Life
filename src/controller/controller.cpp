#include "controller.h"

Controller::Controller() : exit_(false), run_(false), game_started_(false) { }

void Controller::set_game_model(std::shared_ptr<GameModel> game_model)
{
    game_model_ = std::move(game_model);
}

void Controller::process_cell_pressed(int i, int j)
{
    if (game_model_ == nullptr) return;

    game_model_->set_cell_state(i, j);
}

void Controller::process_game_button_pressed()
{
    if (game_model_ == nullptr) return;
    if (!game_started_) game_started_ = true;

    run_ = !run_;

    if (game_started_ == true && run_ == true)
    {
        game_model_->update();
    }
    else
    {
        game_model_->pause();
    }
}

void Controller::end_game() 
{
    if (game_model_ == nullptr) return;

    game_model_->pause(); 

    run_ = false;
}

void Controller::process_exit() { exit_ = true; }

bool Controller::is_stopped() const { return exit_; }

bool Controller::game_has_started() const { return game_started_; }

bool Controller::is_run() const { return run_; }
