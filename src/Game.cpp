#include "Game.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

SDL_Renderer* Game::renderer;
SDL_Window* Game::window;


Game::Game(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    window = SDL_CreateWindow("flappybird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(Game::renderer, SDL_BLENDMODE_BLEND);
    background = new ScrollingBackground;
    player = new Bird;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    TTF_Font* font = TTF_OpenFont("assets/font.ttf", 128);
    SDL_Surface* tmp_surface = TTF_RenderText_Blended(font, "GAME OVER", {255, 0, 0, 0});
    game_over_text = SDL_CreateTextureFromSurface(Game::renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);
    SDL_Surface* tmp_surface1 = TTF_RenderText_Blended(font, "press enter to restart", {100, 100, 100, 255});
    enter_to_continue_text = SDL_CreateTextureFromSurface(Game::renderer, tmp_surface1);
    std::cout << "hello flappybird" << std::endl;
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    delete background;
    delete player;
    for(unsigned i = 0; i < poles.size(); i++){
        delete poles[i];
    }
    std::cout << "goodbye flappybird" << std::endl;
}

void Game::update(unsigned long long frame_count){
    background -> update();
    player -> update();
    for(unsigned i = 0; i < poles.size(); i++){
        poles[i] -> update();
    }
    if(frame_count % 60 == 0){
        poles.push_back(new Pole);
    }
    //cleanup_poles();
    check_collisions();
}

void Game::handle_events(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        is_running = false;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_SPACE:
                player -> jump();
                break;
            case SDLK_x:
                player -> is_freefalling = true;
                break;
            case SDLK_RETURN:
                if(is_over){
                    is_over = false;
                    poles.clear();
                    player->dest_rect = {100, 100, 64, 64};
                }
                break;
            default:
                break;
            }
        break;
    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
        case SDLK_x:
            player -> is_freefalling = false;
            break;
        
        default:
            break;
        }
        break;
    case SDL_MOUSEBUTTONDOWN:
        player -> jump();
        break;
    default:
        break;
    }
}

void Game::render(){
    SDL_RenderClear(renderer);
    background -> render();
    player -> render();
    for(unsigned i = 0; i < poles.size(); i++){
        poles[i] -> render();
    }
    if(is_over){
        SDL_Rect rect = {0, -200, 1920, 1080};
        SDL_Rect rect1 = {0, 860, 1920, 200};
        SDL_RenderCopy(Game::renderer, game_over_text, NULL, &rect);
        SDL_RenderCopy(Game::renderer, enter_to_continue_text, NULL, &rect1);
    }
    SDL_RenderPresent(renderer);
}

void Game::cleanup_poles(){
    for(unsigned i = 0; i < poles.size(); i++){
        if(poles[i]->top_rect.x < 0){
            delete poles[i];
        }
    }
}

void Game::check_collisions(){
    for(unsigned i = 0; i < poles.size(); i++){
        if(player->dest_rect.x > poles[i]->bottom_rect.x && player->dest_rect.x < poles[i]->bottom_rect.x + poles[i]->bottom_rect.w){
            if(player->dest_rect.y > poles[i]->bottom_rect.y || player->dest_rect.y < poles[i]->top_rect.y){
                is_over = true;
            }
        }
    }
}