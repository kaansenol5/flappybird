#include "Game.hpp"

int main(int argc, char* argv[]){
    Game game;
    const unsigned char FPS = 60;
    const int frame_delay = 1000 / FPS;
    unsigned long frame_start;
    int frame_time;
    unsigned long long frame_counter = 0;
    while(game.is_running){
        frame_start = SDL_GetTicks();
        game.render();
        if(!game.is_over){
            game.update(frame_counter);
        }
        game.handle_events();
        frame_counter++;
        frame_time = SDL_GetTicks() - frame_start;
        if(frame_delay > frame_time){
            SDL_Delay(frame_delay - frame_time);
        }
    }
}