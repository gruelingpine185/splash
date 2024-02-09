#include <stdio.h>

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_error.h>

#include "game.h"


int create_game(game_t* _game) {
    if(!_game) return 0;

    if(SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "%s\n", SDL_GetError());
        return 0;   
    }

    _game->window = SDL_CreateWindow("Umbra", 800, 600, 0);
    if(_game->window) {
        fprintf(stderr, "%s\n", SDL_GetError());
        destroy_game(_game);
        return 0;
    }

    _game->renderer = SDL_CreateRenderer(_game->window,
                                        NULL,
                                        SDL_RENDERER_PRESENTVSYNC);
    if(!_game->renderer) {
        fprintf(stderr, "%s\n", SDL_GetError());
        destroy_game(_game);
        return 0;
    }

    return 1;
}

void destroy_game(game_t* _game) {
    if(!_game) return;

    if(_game->renderer) SDL_DestroyRenderer(_game->renderer);
    if(_game->window) SDL_DestroyWindow(_game->window);

    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
}