#include <iostream>
#include "view/interface.h"
#include <boost/program_options.hpp>

namespace po = boost::program_options;

void validate_option(const char* option_name, float value)
{
    if (value <= 0) 
    {
        throw po::validation_error(po::validation_error::invalid_option_value, option_name, std::to_string(value));
    }
}

int main(int argc, char** argv) 
{
    po::options_description desc("Allowed options");

    int field_width;
    int field_height;
    float game_speed;

    try
    {
        desc.add_options()
            ("help,H", "help message")
            ("width,w", po::value<int>()->default_value(5)->notifier([](int value){ validate_option("width", value); }), "width of the game field")
            ("height,h", po::value<int>()->default_value(5)->notifier([](int value){ validate_option("height", value); }), "height of the game field")
            ("speed,s", po::value<float>()->default_value(1.)->notifier([](float value){ validate_option("speed", value); }), "speed of the game");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.contains("help"))
        {
            std::cout << desc << std::endl;
            return 0;
        }

        if (vm.contains("width")) field_width = vm["width"].as<int>();
        if (vm.contains("height")) field_height = vm["height"].as<int>();
        if (vm.contains("speed")) game_speed = vm["speed"].as<float>();
    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }

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

    auto controller = std::make_shared<Controller>();
    auto interface = std::make_shared<Interface>(controller, field_width, field_height);
    auto game_model = std::make_shared<GameModel>(interface, field_width, field_height, game_speed);

    controller->set_game_model(std::move(game_model));

    interface->run();

    SDL_Quit();
    IMG_Quit();

    return 0;
};
