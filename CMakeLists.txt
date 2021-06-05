cmake_minimum_required(VERSION 3.19)
INCLUDE(FindPkgConfig)
project(flappybird)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -lSDL2 -lSDL2_image -lSDL2_ttf -std=c++17 -pthread -O0")
set(CMAKE_CXX_STANDARD 17)


add_executable(
    flappybird
    src/Game.cpp
    src/main.cpp
    src/ScrollingBackground.cpp
    src/Bird.cpp
    src/Pole.cpp
)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})