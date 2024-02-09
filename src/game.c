#include <stddef.h>
#include <stdio.h>

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_error.h>

#include "game.h"


#define checkSDL(_ret_val, _ret) \
    do { \
        if (_ret_val < 0) { \
          fprintf(stderr, "%s\n", SDL_GetError()); \
          destroy_game(_game); \
          return _ret; \
        } \
    } while (0)


int create_game(game_t *_game) {
    if(!_game) return 0;

    checkSDL(SDL_InitSubSystem(SDL_INIT_VIDEO), 0);
    _game->window = SDL_CreateWindow("Umbra", 800, 600, 0);

    checkSDL((!_game->window), 0);
    _game->renderer = SDL_CreateRenderer(_game->window,
                                        NULL,
                                        SDL_RENDERER_PRESENTVSYNC);
    checkSDL((!_game->renderer), 0);

    return 1;
}

void destroy_game(game_t* _game) {
    if(!_game) return;

    if(_game->renderer) SDL_DestroyRenderer(_game->renderer);
    if(_game->window) SDL_DestroyWindow(_game->window);

    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
}
