#include "Pole.hpp"
#include "Game.hpp"

Pole::Pole(){
    int pole_start = rand() % 540 + 200;
    top_rect = {1920, 0, 50, pole_start - 250};
    bottom_rect = {1920, pole_start, 50, 1080 - pole_start};
}

void Pole::render(){
    SDL_SetRenderDrawColor(Game::renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(Game::renderer, &bottom_rect);
    SDL_RenderFillRect(Game::renderer, &top_rect);
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);

}

void Pole::update(){
    bottom_rect.x -= scroll_speed;
    top_rect.x -= scroll_speed;
}