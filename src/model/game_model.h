#pragma once

#include <vector>

class GameModel
{
public:

    GameModel(int field_size);

private:

    // Field data
    std::vector<std::vector<int>> field_;

    // Game field size
    int field_size_;
};
