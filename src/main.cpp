#include <iostream>
#include "view/interface.h"

int main(int argc, char** args) 
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Can't init SDL!\n";
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) 
    {
        std::cerr << "Can't init image: " << IMG_GetError() << std::endl;
        return 1;
    }

    int field_width = 5;
    int field_height = 5;

    auto controller = std::make_shared<Controller>();
    auto interface = std::make_shared<Interface>(controller, field_width, field_height);
    auto game_model = std::make_shared<GameModel>(interface, field_width, field_height);

    controller->set_game_model(std::move(game_model));

    interface->run();

    SDL_Quit();
    IMG_Quit();

    return 0;
};
