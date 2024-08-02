cmake_minimum_required(VERSION 3.10)

project(GameOfLife VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(Boost COMPONENTS program_options REQUIRED)

set(SOURCES
    src/main.cpp
    src/controller/controller.cpp
    src/model/game_model.cpp
    src/view/interface.cpp
    src/view/widgets/cell.cpp
    src/view/widgets/button.cpp
    src/view/widgets/widget.cpp
    src/view/texture_manager/texture_manager.cpp
)

set(HEADERS
    src/controller/controller.h
    src/model/game_model.h
    src/view/interface.h
    src/view/widgets/cell.h
    src/view/widgets/button.h
    src/view/widgets/widget.h
    src/view/texture_manager/texture_manager.h
)

file(COPY img DESTINATION ${PROJECT_BINARY_DIR})

add_executable(GameOfLife ${SOURCES})

target_link_libraries(GameOfLife ${SDL2_LIBRARIES} SDL2_image Boost::program_options)
