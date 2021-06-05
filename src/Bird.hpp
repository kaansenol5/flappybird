#pragma once
#include <SDL2/SDL.h>
#include "config.h"

class Bird{
public:
    Bird();
    ~Bird();
    void update();
    void render();
    void jump();
    bool is_freefalling = false;
    SDL_Rect dest_rect = {100, 100, 64, 64};
private:
    int jump_height = BIRD_JUMP_HEIGHT;
    int jump_speed = BIRD_JUMP_SPEED; // fall_speed + the speed you want
    int jumped_height = 0;
    int fall_speed = BIRD_FALL_SPEED;
    bool is_jumping = false;
    int freefall_speed = BIRD_FREEFALL_SPEED;
    SDL_Texture* texture;
};