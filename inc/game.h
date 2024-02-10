#ifndef GAME_H
#define GAME_H


namespace splash {
    class game;
    class window;

    enum class game_state;

    
    enum class game_state {
        quit,
        running
    };


    class game {
    public:
        game(const game& _game) = delete;
        game();
        ~game();

        void poll_events(window& _win);
        void render(window& _win);
        game_state get_state() const;
    private:
        game_state _state;
    };
}

#endif // GAME_H
