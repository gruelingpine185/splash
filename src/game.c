#include <stddef.h>

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_events.h>

#include "utils.h"
#include "game.h"


#ifndef GAME_NAME
    #define GAME_NAME ""
#endif // GAME_NAME
#ifndef GAME_WIDTH
    #define GAME_WIDTH 960
#endif // GAME_WIDTH
#ifndef GAME_HEIGHT
    #define GAME_HEIGHT 540
#endif // GAME_HEIGHT


int create_game(game_t *_game) {
    if(!_game) return 0;

    checkSDL(SDL_InitSubSystem(SDL_INIT_VIDEO), 0);

    _game->window = SDL_CreateWindow(GAME_NAME, GAME_WIDTH, GAME_HEIGHT, 0);
    if(!_game->window) {
        fprintf(stderr, "%s\n", SDL_GetError());
        return 0;
    }

    _game->renderer = SDL_CreateRenderer(_game->window,
                                        NULL,
                                        SDL_RENDERER_PRESENTVSYNC);
    if(!_game->renderer) {
        fprintf(stderr, "%s\n", SDL_GetError());
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

int render_game(game_t* _game) {
    if(!_game) return 0;

    checkSDL(SDL_SetRenderDrawColor(_game->renderer, 0x18, 0x18, 0x18, 0xff), 0);
    checkSDL(SDL_RenderClear(_game->renderer), 0);

    checkSDL(SDL_RenderPresent(_game->renderer), 0);
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
