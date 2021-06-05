#pragma once
#include <SDL2/SDL.h>
#include "config.h"


class Pole{
public:
    Pole();
    void render();
    void update();
    SDL_Rect bottom_rect;
    SDL_Rect top_rect;    
private:
    int scroll_speed = BACKGROUND_SCROLL_SPEED;
};