#ifndef GAME_H
#define GAME_H


typedef enum {
    GAME_STATE_QUIT,
    GAME_STATE_RUNNING
} game_state_t;


typedef struct game_t game_t;

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;


struct game_t {
    SDL_Window* window;
    SDL_Renderer* renderer;
    game_state_t state;
};


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
int create_game(game_t* _game);
void destroy_game(game_t* _game);
int render_game(game_t* _game);
void game_poll_events(game_t* _game);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // GAME_H
