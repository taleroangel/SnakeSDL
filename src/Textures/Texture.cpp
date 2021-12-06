#pragma once

#include "Texture.hpp"
#include "../Exceptions/Exceptions.hpp"
#include "../Utils/Utils.hpp"
#include <typeinfo>

Texture::Texture(SDL_Renderer *renderer, std::string filename, Logging *logs)
    : renderer(renderer), log(logs)
{
    // Renderer reference
    if (renderer == nullptr)
        throw InvalidRenderer();

    texture = loadTexture(this->renderer, filename);
    if (texture == NULL)
    {
        throw InvalidTexture();

        // Show LOG information
        if (this->log != nullptr)
            log->print(typeid(this).name(), std::string("Texture '") + filename + std::string(" failed to load"),
                       Logging::InfoType::WARNING);
    }

    // Show LOG information
    else if (this->log != nullptr)
        log->print(typeid(this).name(),
                   std::string("Texture '") + filename + std::string("' loaded into memory!"));
}

Texture::Texture(SDL_Renderer *renderer, Logging *logs)
    : renderer(renderer), log(logs)
{
    // Renderer reference
    if (renderer == nullptr)
        throw InvalidRenderer();

    else if (log != nullptr)
        log->print(typeid(this).name(), "Render assignment successfull");
}

Texture::~Texture()
{
    // Destroy any rectangle
    setNullSize();

    // Destroy the resources
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);

        // Show LOG information
        if (this->log != nullptr)
            log->print(typeid(this).name(), "Texture destroyed");
    }

    // Show LOG information
    else if (this->log != nullptr)
        log->print(typeid(this).name(), "Texture reference was NULL, object skipped",
                   Logging::InfoType::WARNING);
}

bool Texture::renderTexture()
{
    if (SDL_RenderCopy(
            this->renderer,
            this->texture,
            this->srcRect,
            this->texturePropierties) != 0)
    {
        this->log->print(typeid(this).name(),
                         "Failed to load texture",
                         Logging::InfoType::ERROR);

        return false;
    }

    return true;
}

SDL_Texture *const Texture::getTexture() const
{
    return this->texture;
}

void Texture::setCoordinates(int x, int y)
{
    if (texturePropierties == nullptr)
    {
        this->texturePropierties = new SDL_Rect;

        int gw, gh;
        SDL_QueryTexture(
            this->texture, NULL, NULL, &gw, &gh);

        this->setSize(gh, gw);
    }

    this->texturePropierties->x = x;
    this->x_coord = x;
    this->texturePropierties->y = y;
    this->y_coord = y;
}

void Texture::setSize(int h, int w)
{
    if (texturePropierties == nullptr)
    {
        this->texturePropierties = new SDL_Rect;
        this->setCoordinates(0, 0);
    }

    this->texturePropierties->h = h;
    this->height = h;
    this->texturePropierties->w = w;
    this->width = w;
}

void Texture::setDefaultSize()
{
    this->setCoordinates(0, 0);
}

void Texture::setNullSize()
{
    if (texturePropierties != nullptr)
        delete this->texturePropierties;

    this->texturePropierties = nullptr;

    this->x_coord = 0;
    this->y_coord = 0;
    this->height = 0;
    this->width = 0;
}

void Texture::setSourceRect(SDL_Rect *newSource)
{
    this->srcRect = newSource;
}

const SDL_Rect *const Texture::getRect() const
{
    return this->texturePropierties;
}