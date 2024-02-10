#ifndef UTILS_H
#define UTILS_H


#include <stdexcept>

#include <SDL3/SDL_error.h>


#define checkSDL(_ret_val) \
    do { \
        if(_ret_val < 0) { \
            throw std::runtime_error(SDL_GetError()); \
        } \
    } while(0)

#define checkSDL2(_ret_val) \
    do { \
        if(!(_ret_val)) { \
            throw std::runtime_error(SDL_GetError()); \
        } \
    } while(0)

#endif // UTILS_H
