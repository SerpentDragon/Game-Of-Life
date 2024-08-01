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

    Interface interface(7);
    interface.run();

    SDL_Quit();
    IMG_Quit();

    return 0;
};
