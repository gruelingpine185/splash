#include <stddef.h>
#include <stdio.h>

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_error.h>

#include "game.h"


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

int render_game(game_t* _game) {
    if(!_game) return 0;

    checkSDL(SDL_SetRenderDrawColor(_game->renderer, 0xff, 0xff, 0xff, 0xff), 0);
    checkSDL(SDL_RenderClear(_game->renderer), 0);

    return 1;
}

void game_poll_events(game_t* _game) {
    if(!_game) return;

    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_EVENT_QUIT:
                _game->state = GAME_STATE_QUIT;
                break;
            default:
                break;
        }
    }
}
