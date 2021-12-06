/**
 * @file Texture.hpp
 * @author Ángel Talero (angelgotalero@outlook.com)
 * @brief Texture abstract class
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

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "Sprite.h"
#include "../Logging/Logging.hpp"

#pragma once

/**
 * @class Texture
 * @brief Texture abstraction class
 */
class Texture
{
    /* Private variables */
protected:
    SDL_Renderer *renderer = nullptr; /**< Renderer reference*/
    SDL_Texture *texture = nullptr;   /**< Texture SDL reference*/

    SDL_Rect *srcRect = NULL;               /**< Source rectangle container*/
    SDL_Rect *texturePropierties = nullptr; /**< Rectangle propierties*/

    Logging *log = nullptr; /**< Logging monitor*/

    /* Public variables */
public:
    int height = 0; /**< Texture height*/
    int width = 0;  /**< Texture width*/

    int x_coord = 0; /**< Texture X coordinate*/
    int y_coord = 0; /**< Texture Y coordinate*/

    /* Public member functions */
public:
    /**
     * @brief Construct a new Texture object
     * 
     * @param renderer Renderer reference
     * @param filename Filename of the texture file
     * @param logs Log reference or NULL
     */
    Texture(
        SDL_Renderer *renderer,
        std::string filename,
        Logging *logs) noexcept(false);

    /**
     * @brief Destroy the Texture object
     * 
     */
    virtual ~Texture();

protected:
    /**
     * @brief Construct a new Texture object with no texture initialization
     * 
     * @param renderer Renderer reference
     * @param logs Log reference or NULL
     */
    Texture(SDL_Renderer *renderer, Logging *logs);

public:

    /**
     * @brief Copy texture to the renderer
     * 
     * @return true Texture was loaded correctly
     * @return false Texture failed to load
     */
    virtual bool renderTexture();

    /**
     * @brief Get the Texture object
     * 
     * @return SDL_Texture* const Const pointer to the texture
     */
    virtual SDL_Texture *const getTexture() const;

    /**
     * @brief Set the Coordinates for the object
     * 
     * @param x X coordinate
     * @param y Y coordinate
     */
    virtual void setCoordinates(int x, int y);

    /**
     * @brief Set the Size for the object
     * 
     * @param h Height
     * @param w Width
     */
    virtual void setSize(int h, int w);

    /**
     * @brief Set a default size and position (0, 0) for an object
     * 
     */
    virtual void setDefaultSize();

    /**
     * @brief Set the SDL_Rect object to NULL
     * 
     */
    virtual void setNullSize();

    /**
     * @brief Set the Source Rectangle reference
     * 
     * @param newSource 
     */
    void setSourceRect(SDL_Rect *newSource);

    /**
     * @brief Get the current Rectangle propierty
     * 
     * @return SDL_Rect* Pointer to the rectangle
     */
    const SDL_Rect *const getRect() const;
};