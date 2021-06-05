#include <SDL2/SDL.h>
#include "ScrollingBackground.hpp"
#include "Bird.hpp"
#include "Pole.hpp"
#include <vector>
#include <SDL2/SDL_ttf.h>

class Game{
public:
    Game();
    ~Game();
    void update(unsigned long long frame_count);
    void render();
    void handle_events();
    bool is_running = true; // means we dont want the game to exit
    bool is_over = false; // means the player did not lose yet
    static SDL_Renderer* renderer;
private:
    TTF_Font* font;
    unsigned score = 0;
    void cleanup_poles();
    void check_collisions();
    static SDL_Window* window;
    SDL_Texture* game_over_text;
    SDL_Texture* enter_to_continue_text;
    ScrollingBackground* background;
    Bird* player;
    std::vector<Pole*> poles;
};