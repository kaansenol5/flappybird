#include "ScrollingBackground.hpp"
#include "Game.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

ScrollingBackground::ScrollingBackground(){
    SDL_Surface* tmp_surface = IMG_Load("assets/background.png");
    background_image = SDL_CreateTextureFromSurface(Game::renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);
}

ScrollingBackground::~ScrollingBackground(){
    SDL_DestroyTexture(background_image);
}

void ScrollingBackground::render(){
    SDL_RenderCopy(Game::renderer, background_image, NULL, &first_location);
    SDL_RenderCopy(Game::renderer, background_image, NULL, &second_location);
}

void ScrollingBackground::update(){
    first_location.x -= scroll_speed;
    second_location.x -= scroll_speed;
    if(second_location.x == 0){
        first_location = {0, 0, 1920, 1080};
        second_location = {1920, 0, 1920, 1080};
    }
}