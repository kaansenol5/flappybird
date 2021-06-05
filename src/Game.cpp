#include "Game.hpp"
#include <iostream>

SDL_Renderer* Game::renderer;

Game::Game(){
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("flappybird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    std::cout << "hello flappybird" << std::endl;
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "goodbye flappybird" << std::endl;
}