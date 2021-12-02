#include "Utils.hpp"

#include <SDL2/SDL_image.h>
#include <cstdlib>

SDL_Surface *loadSurface(SDL_Surface *mainSurface, std::string path)
{
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
        return nullptr;

    SDL_Surface *optimizedSurface = SDL_ConvertSurface(
        loadedSurface, mainSurface->format, 0);

    if (optimizedSurface == NULL)
    {
        SDL_FreeSurface(loadedSurface);
        return nullptr;
    }

    SDL_FreeSurface(loadedSurface);
    return optimizedSurface;
}

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, path.c_str());
    if (texture == NULL)
        return nullptr;

    return texture;
}

bool InitSDL()
{
    // SDL Initialization
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;

    // Image subsystem initialization
    int IMAGE_FLAGS = IMG_INIT_PNG;
    int IMAGE_INITS = IMG_Init(IMAGE_FLAGS);
    if ((IMAGE_FLAGS & IMAGE_INITS) != IMAGE_FLAGS)
        return false;

    // Stop subsystems at exit
    std::atexit(SDL_Quit);
    std::atexit(IMG_Quit);

    return true;
}