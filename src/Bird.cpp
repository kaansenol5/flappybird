#include "Bird.hpp"
#include "Game.hpp"
#include <SDL2/SDL_image.h>

Bird::Bird(){
    SDL_Surface* tmp_surface = IMG_Load("assets/bird.png");
    texture = SDL_CreateTextureFromSurface(Game::renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);
}

Bird::~Bird(){
    SDL_DestroyTexture(texture);
}

void Bird::render(){
    SDL_RenderCopy(Game::renderer, texture, NULL, &dest_rect);
}

void Bird::update(){
    dest_rect.y += fall_speed;
    if(is_jumping == true){
        dest_rect.y -= jump_speed;
        jumped_height += jump_speed;
        if(jumped_height >= jump_height){
            is_jumping = false;
            jumped_height = 0;
        }

    }
    if(is_freefalling){
        is_jumping = false;
        dest_rect.y += freefall_speed;
    }
}

void Bird::jump(){
    is_jumping = true;
    dest_rect.y -= 16;
}