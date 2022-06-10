cmake_minimum_required(VERSION 3.22)
project(gol)

set(CMAKE_CXX_STANDARD 20)

include_directories(/opt/homebrew/Cellar/sdl2/2.0.22/include)
link_directories(/opt/homebrew/Cellar/sdl2/2.0.22/lib)
add_executable(gol game.cpp Board.h constants.h)
target_link_libraries(gol SDL2)