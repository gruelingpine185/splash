#include "game.h"


int main(void) {
    game_t game = {0};
    if(!create_game(&game)) return 1;

    game.state = GAME_STATE_RUNNING;
    while(game.state != GAME_STATE_QUIT) {
        if(!render_game(&game)) {
            destroy_game(&game);
            return 1;
        }

        game_poll_events(&game);
    }

    destroy_game(&game);
    return 0;
}
