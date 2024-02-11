#include <stdexcept>

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_events.h>

#include "window.h"


namespace splash {
    window::window(int _w, int _h, const std::string& _title):
        _window(nullptr), _renderer(nullptr), _w(_w),
        _h(_h), _title(_title) {}

    window::window():
        _window(nullptr), _renderer(nullptr), _w(),
        _h(), _title() {}

    window::~window() {
        SDL_DestroyRenderer(this->_renderer);
        SDL_DestroyWindow(this->_window);
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
        SDL_Quit();
    }

    void window::create() {
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            throw std::runtime_error(SDL_GetError());
        }

        this->_window = SDL_CreateWindow(this->_title.c_str(),
                                            this->_w,
                                            this->_h,
                                            0);
        if(!this->_window) throw std::runtime_error(SDL_GetError());

        this->_renderer = SDL_CreateRenderer(this->_window,
                                                nullptr,
                                                SDL_RENDERER_PRESENTVSYNC);
        if(!this->_renderer) throw std::runtime_error(SDL_GetError());
    }

    void window::create(int _w, int _h, const std::string& _title) {
        this->_w = _w;
        this->_h = _h;
        this->_title = _title;
        this->create();
    }

    void window::handle_events(const SDL_Event& _event) {
        (void) _event;
    }

    int window::w() const {
        return this->_w;
    }

    int window::h() const {
        return this->_h;
    }
  
    std::string window::title() const {
        return this->_title;
    }

    SDL_Renderer* window::renderer() const {
        return this->_renderer;
    }
}
