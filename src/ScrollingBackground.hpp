#pragma once
#include <SDL2/SDL.h>
#include "config.h"
class ScrollingBackground{
public:
    ScrollingBackground();
    ~ScrollingBackground();
    void render();
    void update();
private:
    int scroll_speed = BACKGROUND_SCROLL_SPEED;
    SDL_Texture* background_image;
    SDL_Rect first_location = {0, 0, 1920, 1080};
    SDL_Rect second_location = {1920, 0, 1920, 1080};
};