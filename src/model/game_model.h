#pragma once

#include <thread>
#include <memory>
#include <vector>

using field_data = std::vector<std::vector<unsigned short>>;

class Interface;

class GameModel : public std::enable_shared_from_this<GameModel>
{
public:

    GameModel(std::shared_ptr<Interface> interface, 
        int field_width, int field_height, float game_speed);

    // Set specified cell alive
    void set_cell_state(int i, int j);

    // Updated the game field (calculate the next state)
    void update();

    // Sen field state
    void update_field();

    bool is_run() const;

    void pause();

private:

    enum STATE : unsigned short { DEAD = 0, ALIVE };

private:

    std::shared_ptr<Interface> interface_;

    // Field data
    field_data field_;
    field_data prev_config_;

    // Game field size
    int field_width_;
    int field_height_;

    // Game is on or not
    bool run_;

    // Define the value of delay
    float game_speed_;
};
