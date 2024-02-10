#ifndef WINDOW_H
#define WINDOW_H


#include <string>


struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;


namespace splash {
    class window;


    class window {
    public:
        window(int _w, int _h, const std::string& _title);
        window(const window& _win) = delete;
        window();
        ~window();

        void create(int _w, int _h, const std::string& _title);
        void create();
        void handle_events(const SDL_Event& _event);
        int get_w() const;
        int get_h() const;
        std::string get_title() const;
        SDL_Renderer* get_renderer() const;
        SDL_Event get_event() const;
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        int _w;
        int _h;
        std::string _title;
    };
}

#endif // WINDOW_H
