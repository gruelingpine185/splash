#include <iostream>

#include "window.h"
#include "game.h"


int main() {
    try {
        splash::window window(960, 540, "Splash");
        splash::game game;

        window.create();

        while(game.get_state() != splash::game_state::quit) {
            game.render(window);
            game.poll_events(window);
        }
    } catch(const std::exception& _e) {
        std::cerr << _e.what() << std::endl;
    }

    return 0;
}
