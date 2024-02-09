#ifndef GAME_H
#define GAME_H


typedef struct game_t game_t;

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;


struct game_t {
    SDL_Window* window;
    SDL_Renderer* renderer;
};


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
int create_game(game_t* _game);
void destroy_game(game_t* _game);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // GAME_H
