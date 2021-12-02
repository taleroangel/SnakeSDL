/**
 * @file main.cpp
 * @author Ángel Talero (angelgotalero@outlook.com)
 * @brief Snake SDL2
 * @version 0.1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) 2021. Angel D. Talero
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/* ---- Libraries ---- */

// Standard libraries
#include <cstdlib>
#include <iostream>

// Other libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// Headers
#include "Logging/Logging.hpp"
#include "Utils/Utils.hpp"

/* ---- Variables and constants ---- */
#define GAME_NAME "Snake SDL"         /**< Game name*/
#define LOG_FILENAME "snake_logs.txt" /**< Logs filename*/

constexpr int SCREEN_WIDTH = 500;  /**< Screen width dimentions*/
constexpr int SCREEN_HEIGHT = 500; /**< Screen height dimentions*/

volatile bool isRunning = true; /**< Game running flag */

/* ---- Main ---- */
int main(int argc, char *argv[])
{
    //* 1. Logging monitor initialization
    Logging log(LOG_FILENAME, false); //TODO: Leave to true
    if (log.isFailed())
        return EXIT_FAILURE;

    //* 2. SDL initialization
    if (!InitSDL())
    {
        log.print("SDL", SDL_GetError(), Logging::InfoType::ERROR);
        return EXIT_FAILURE;
    }
    else
        log.print("SDL", "SDL SubSystems initialization succeeded");

    //* 3. Create Windows
    // Create window and surfaces
    SDL_Window *mainWindow = SDL_CreateWindow(
        /* Window title */ GAME_NAME,
        /* Position */ SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        /* Size */ SCREEN_WIDTH, SCREEN_HEIGHT,
        /* Flags */ SDL_WINDOW_SHOWN);

    // Check
    if (mainWindow == NULL)
    {
        log.print("SDL", SDL_GetError(), Logging::InfoType::ERROR);
        return EXIT_FAILURE;
    }

    //* 4. Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(
        mainWindow, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) // Renderer failed
    {
        // Deallocate resources
        SDL_DestroyWindow(mainWindow);
        mainWindow = nullptr;

        // SDL error exit
        log.print("SDL", SDL_GetError(), Logging::InfoType::ERROR);
        return EXIT_FAILURE;
    }

    // Setup renderer color
    if (SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF) < 0)
        log.print("SDL", SDL_GetError(), Logging::InfoType::ERROR);

    //* 5. Main Loop
    SDL_Event nextEvent;
    while (isRunning)
    {
        // Render the screen using GPU
        SDL_RenderPresent(renderer);

        // Dequeue an event
        while (SDL_PollEvent(&nextEvent))
        {
            switch (nextEvent.type)
            {
            case SDL_QUIT:
                log.print("Event", "User requested exit");
                isRunning = false;
                break;

            default:
                break;
            }
        }
    }

    //! Deallocate textures

    //! Destroy renderer
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;

    //! Deallocate resources
    SDL_DestroyWindow(mainWindow);
    mainWindow = nullptr;

    return EXIT_SUCCESS;
}
