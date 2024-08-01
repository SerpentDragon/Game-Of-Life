#include "game_model.h"
#include "../view/interface.h"

GameModel::GameModel(std::shared_ptr<Interface> interface, 
    int field_width, int field_height) 
    : interface_(interface), field_width_(field_width), 
    field_height_(field_height), run_(false)
{
    field_.resize(field_height);

    for(int i = 0; i < field_height; i++) 
    {
        field_[i].resize(field_width, 0);
    }
}

void GameModel::set_cell_state(int i, int j)
{
    field_[i][j] = field_[i][j] == 0 ? 1 : 0;

    interface_->update_field(field_);
}

void GameModel::update_field()
{
    static int val = 0;
    if (val++ == 5) return;

    std::vector<std::vector<unsigned short>> neighbors(
        field_height_, std::vector<unsigned short>(field_width_, 0));

    for(int i = 0; i < field_height_; i++)
    {
        for(int j = 0; j < field_width_; j++)
        {
            int l = (j == 0 ? field_width_ : j) - 1; // left
            int r = (j + 1) % field_width_; // right
            int t = (i == 0 ? field_height_ : i) - 1; // top
            int b = (i + 1) % field_height_; // bottom

            neighbors[i][j] = (field_[t][l] == STATE::ALIVE) + 
                (field_[t][j] == STATE::ALIVE) + (field_[t][r] == STATE::ALIVE) + 
                (field_[i][l] == STATE::ALIVE) + (field_[i][r] == STATE::ALIVE) + 
                (field_[b][l] == STATE::ALIVE) + (field_[b][j] == STATE::ALIVE) + 
                (field_[b][r] == STATE::ALIVE);
        }
    }

    for(int i = 0; i < field_height_; i++)
    {
        for(int j = 0; j < field_width_; j++)
        {
            if (neighbors[i][j] == 3) 
            {
                field_[i][j] = STATE::ALIVE;
            }
            else if (neighbors[i][j] < 2 || neighbors[i][j] > 3)
            {
                field_[i][j] = STATE::DEAD;
            }
        }
    }

    interface_->update_field(field_);

    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void GameModel::update()
{
    run_ = true;
    auto this_ptr = this->shared_from_this();

    std::thread th([this_ptr]()
    {
        while(this_ptr->is_run())
        {
            this_ptr->update_field();
        }
    });

    th.detach();
}

bool GameModel::is_run() const { return run_; }

void GameModel::pause() { run_ = false; }
