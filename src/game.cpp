#include <stdexcept>

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>

#include "utils.h"
#include "window.h"
#include "game.h"


namespace splash {
    game::game():
        _state(game_state::running) {}

    game::~game() {}

    void game::poll_events(window& _win) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_EVENT_QUIT:
                    this->_state = game_state::quit;
                    break;
                default:
                    _win.handle_events(event);
                    break;
            }
        }
    }

    void game::render(window& _win) {
        checkSDL(SDL_SetRenderDrawColor(_win.get_renderer(), 0x14, 0x14, 0x14, 0xff));
        checkSDL(SDL_RenderClear(_win.get_renderer()));
        checkSDL(SDL_RenderPresent(_win.get_renderer()));
    }

    game_state game::get_state() const {
        return this->_state;
    }
}
