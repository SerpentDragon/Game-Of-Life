#include "interface.h"

Interface::Interface(std::shared_ptr<Controller> controller, int field_width, int field_height) 
    : controller_(controller), field_width_(field_width), field_height_(field_height)
{
    init_window();
    init_texture_manager();
    init_widgets();
}

Interface::~Interface()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
}

void Interface::run()
{   
    SDL_Event event;

    while (true)
    {
        auto controller = controller_.lock();
        if (controller == nullptr) break;

        if (controller->is_stopped()) break;

        while(SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT) 
            {
                if (!controller->is_stopped()) controller->process_exit();
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                handle_mouse_event();
            }
        }

        SDL_RenderClear(renderer_); 

        display_background();

        display_button();

        display_game_field();

        if (!controller->is_run() && controller->game_has_started())
        {
            display_game_over();
            controller->set_game_over();
        }

        SDL_RenderPresent(renderer_);
    }
}

void Interface::update_field(field_data new_field)
{
    for(int i = 0; i < field_height_; i++)
    {
        for(int j = 0; j < field_width_; j++)
        {
            field_[i][j].set_state(new_field[i][j]);
        }
    }
}

void Interface::stop()
{
    auto controller = controller_.lock();
    if (controller == nullptr) return;

    controller->pause_game();
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

    // if (window_ == nullptr || renderer_ == nullptr);
}

void Interface::init_texture_manager()
{
    TextureManager::get_manager()->set_renderer(renderer_);
    TextureManager::get_manager()->load_textures();
}

void Interface::init_widgets()
{
    // Init game button
    int button_size = window_height_ / 10;
    int x = (window_width_ - button_size) / 2;
    int y = window_height_ - 1.25 * button_size;

    game_button_ = Button(renderer_, x, y, button_size, button_size);

    // Init game field
    cell_size_ = std::min(window_width_, window_height_ - int(button_size * 1.5)) / 
        (std::max(field_width_, field_height_) + 2);
    left_top_x_ = (window_width_ - cell_size_ * field_width_) / 2;
    left_top_y_ = (window_height_ - int(button_size * 1.5) - field_height_ * cell_size_) / 2;

    for(int i = 0; i < field_height_; i++)
    {
        field_.emplace_back(field_width_);

        for(int j = 0; j < field_width_; j++)
        {
            field_[i][j] = Cell(renderer_, left_top_x_ + cell_size_ * j, 
                left_top_y_ + cell_size_ * i, cell_size_);
        }
    }
}

void Interface::display_background()
{
    static auto background = TextureManager::get_manager()
        ->get_texture("background/background");

    SDL_RenderCopy(renderer_, background, nullptr, nullptr);
}

void Interface::display_game_field()
{
    for(int i = 0; i < field_height_; i++)
    {
        for(int j = 0; j < field_width_; j++)
        {
            field_[i][j].draw();
        }
    }
}

void Interface::display_button()
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    game_button_.on_button(x, y);
    game_button_.draw();
}

void Interface::display_game_over()
{
    static SDL_Texture* texture = 
        TextureManager::get_manager()->get_texture("background/game_over");
    int width = window_width_ * 0.6;
    int height = width * 0.25;
    int x = (window_width_ - width) / 2;
    int y = (window_height_ - height) / 2;

    static SDL_Rect rect { x, y, width, height };

    SDL_RenderCopy(renderer_, texture, nullptr, &rect);
}

void Interface::handle_mouse_event()
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    auto controller = controller_.lock();
    if (controller == nullptr) return;

    if (controller->game_over()) return;

    if (!controller->game_has_started())
    {
        if (left_top_x_ <= x && x <= left_top_x_ + cell_size_ * field_width_ && 
            left_top_y_ <= y && y <= left_top_y_ + cell_size_ * field_height_)
        {
            int cell_x = (x - left_top_x_) / cell_size_;
            int cell_y = (y - left_top_y_) / cell_size_;

            controller->process_cell_pressed(cell_y, cell_x);
        }
    }
    
    if (game_button_.is_pressed(x, y))
    {
        controller->process_game_button_pressed();
    }
}
