#ifndef UTILS_H
#define UTILS_H


#include <SDL3/SDL_error.h>


#define checkSDL(_ret_val, _ret) \
    do { \
        if (_ret_val < 0) { \
          fprintf(stderr, "%s\n", SDL_GetError()); \
          destroy_game(_game); \
          return _ret; \
        } \
    } while (0)

#endif // UTILS_H
