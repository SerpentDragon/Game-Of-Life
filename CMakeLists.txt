cmake_minimum_required(VERSION 3.10)

project(GameOfLife VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

set(SOURCES
    src/main.cpp
)

# set(HEADERS)

add_executable(GameOfLife ${SOURCES})

target_include_directories(GameOfLife PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(GameOfLife ${SDL2_LIBRARIES})
