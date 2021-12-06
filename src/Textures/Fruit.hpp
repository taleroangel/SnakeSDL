/**
 * @file Fruit.hpp
 * @author Ángel Talero (angelgotalero@outlook.com)
 * @brief Fruit texture abstraction layer
 * @version 0.1
 * @date 2021-12-02
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

#pragma once

#include "Texture.hpp"

#include <initializer_list>
#include <vector>
#include <string>

#include "../Logging/Logging.hpp"

/**
 * @class Fruit
 * @brief Fruit texture abstraction class
 */
class Fruit : public Texture
{
    /* Private member variables */
private:
    std::vector<SDL_Texture *> textures;

    /* Public constants */
public:
    const int icon_size = SPRITE_SIZE;

    /* Constructor */
public:
    Fruit(SDL_Renderer *renderer,
          std::initializer_list<std::string> files, Logging *logs) noexcept(false);

    ~Fruit();

    /* Parent member hiding */
private:
    using Texture::height;
    using Texture::width;

    using Texture::setNullSize;
    using Texture::setSize;

    /* Method overriding */
public:
    /**
     * @brief Get a random fruit texture
     * 
     * @return SDL_Texture* const 
     */
    SDL_Texture *const getTexture() const override;

    bool renderTexture() override;
};