#pragma once

#include <thread>
#include <memory>
#include <vector>

class Interface;

class GameModel : public std::enable_shared_from_this<GameModel>
{
public:

    GameModel(std::shared_ptr<Interface> interface, int field_width, int field_height);

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
    std::vector<std::vector<unsigned short>> field_;

    // Game field size
    int field_width_;
    int field_height_;

    bool run_;
};
