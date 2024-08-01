#include "game_model.h"

GameModel::GameModel(int field_size) : field_size_(field_size)
{
    field_.resize(field_size);

    for(int i = 0; i < field_size; i++) 
    {
        field_[i].resize(field_size);
    }
}
