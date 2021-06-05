#include <SDL2/SDL.h>

class Game{
public:
    Game();
    ~Game();
    void update();
    void render();
    bool is_running = true;
    static SDL_Renderer* renderer;
private:
    static SDL_Window* window;
};