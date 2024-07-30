#include "controller/interface.h"

int main(int argc, char** args) 
{
    if(SDL_Init(SDL_INIT_EVERYTHING ) != 0)
    {
        return 1;
    }

    Interface interface;
    interface.run();
    
    SDL_Quit();

    return 0;
};
