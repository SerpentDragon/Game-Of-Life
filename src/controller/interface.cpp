#include "interface.h"

Interface::Interface(int field_size) : field_size_(field_size)
{
    init_window();
    init_texture_manager();
    init_game_field();
    init_button();
}

Interface::~Interface()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
}

void Interface::run()
{
    auto background = TextureManager::get_manager()->get_texture("background/background");

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
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                handle_mouse_event();
            }
        }
        
        SDL_RenderClear(renderer_);      

        SDL_RenderCopy(renderer_, background, nullptr, nullptr);

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

void Interface::init_texture_manager()
{
    TextureManager::get_manager()->set_renderer(renderer_);
    TextureManager::get_manager()->load_textures();
}

void Interface::init_game_field()
{
    cell_size_ = std::min(window_width_, window_height_) / (field_size_ + 2);
    left_top_x_ = (window_width_ - cell_size_ * field_size_) / 2;
    left_top_y_ = cell_size_ / 2;

    for(int i = 0; i < field_size_; i++)
    {
        field_.emplace_back(field_size_);

        for(int j = 0; j < field_size_; j++)
        {
            field_[i][j] = Cell(renderer_, left_top_x_ + cell_size_ * i, 
                left_top_y_ + cell_size_ * j, cell_size_);
        }
    }
}

void Interface::init_button()
{
    int width = window_width_ / 15;
    int height = window_height_ / 10;
    int x = (window_width_ - width) / 2;
    int y = left_top_y_ + (cell_size_ + 0.5) * field_size_;

    game_button_ = Button(renderer_, x, y, width, height);
}

void Interface::display_game_field()
{
    for(int i = 0; i < field_size_; i++)
    {
        for(int j = 0; j < field_size_; j++)
        {
            field_[i][j].draw();
        }
    }
}

void Interface::handle_mouse_event()
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    if (left_top_x_ <= x && x <= left_top_x_ + cell_size_ * field_size_ && 
        left_top_y_ <= y && y <= left_top_y_ + cell_size_ * field_size_)
    {
        int cell_x = (x - left_top_x_) / cell_size_;
        int cell_y = (y - left_top_y_) / cell_size_;

        bool alive = field_[cell_x][cell_y].is_alive();
        field_[cell_x][cell_y].set_state(!alive);
    }
}
