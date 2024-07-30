#include "interface.h"

Interface::Interface(int field_size) : field_size_(field_size)
{
    init_window();
    init_background();
    init_game_field();
}

Interface::~Interface()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
}

void Interface::run()
{
    bool run = true;
    SDL_Event event;

    while (run) 
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT) 
            {
                run = false;
            }
        }
        
        SDL_RenderClear(renderer_);

        SDL_RenderCopy(renderer_, background_, nullptr, nullptr);

        display_game_field();

        SDL_RenderPresent(renderer_);
    }
}

void Interface::init_window()
{
    SDL_DisplayMode displayMode;
    if (SDL_GetCurrentDisplayMode(0, &displayMode) != 0)
    {
        screen_width_ = 0;
        screen_height_ = 0;
    }
    else
    {
        screen_width_ = displayMode.w;
        screen_height_ = displayMode.h;
    }

    window_width_ = 3 * screen_width_ / 5;
    window_height_ = 4 * screen_height_ / 5;

    window_ = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, window_width_, window_height_, SDL_WINDOW_SHOWN);

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | 
        SDL_RENDERER_PRESENTVSYNC);
}

void Interface::init_background()
{
    background_ = IMG_LoadTexture(renderer_, "img/background.bmp");
}

void Interface::init_game_field()
{
    int cell_size = std::min(window_width_, window_height_) / (field_size_ + 2);
    int left_top_x = (window_width_ - cell_size * field_size_) / 2;
    int left_top_y = cell_size;

    for(int i = 0; i < field_size_; i++)
    {
        field_.emplace_back(field_size_);

        for(int j = 0; j < field_size_; j++)
        {
            field_[i][j] = Cell(left_top_x + cell_size * i, 
                left_top_y + cell_size * j, cell_size);
        }
    }
}

void Interface::display_game_field()
{

    for(int i = 0; i < field_size_; i++)
    {
        for(int j = 0; j < field_size_; j++)
        {
            SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer_, &field_[i][j].get_cell_rect());

            SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer_, &field_[i][j].get_cell_rect());
        }
    }
}
