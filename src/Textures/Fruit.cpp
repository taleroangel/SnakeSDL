#include "Fruit.hpp"
#include "../Utils/Utils.hpp"
#include "../Exceptions/Exceptions.hpp"
#include <typeinfo>

Fruit::Fruit(SDL_Renderer *renderer,
             std::initializer_list<std::string> files, Logging *logs) noexcept(false)
    : Texture(renderer, logs)
{
    if (log != nullptr)
        log->print(typeid(this).name(), "Parent constructor just ended...");

    // Set the size
    this->setSize(this->icon_size, this->icon_size);

    // Open each texture
    for (auto file : files)
    {
        // Load texture
        if (renderer == nullptr)
            throw InvalidRenderer();

        SDL_Texture *texture = loadTexture(renderer, file);
        if (texture == nullptr)
        {
            throw InvalidTexture();

            // Show LOG information
            if (this->log != nullptr)
                log->print(typeid(this).name(), std::string("Texture '") + file + std::string(" failed to load"),
                           Logging::InfoType::WARNING);
        }

        // Show LOG information
        else if (this->log != nullptr)
            log->print(typeid(this).name(),
                       std::string("Texture '") + file + std::string("' loaded into memory!"));

        // Pushback into vector
        textures.push_back(texture);
        texture = nullptr;
    }
}

Fruit::~Fruit()
{
    int counter = 0;
    for (auto texture : textures)
    {
        SDL_DestroyTexture(texture);

        if (this->log != nullptr)
            log->print(typeid(this).name(),
                       std::string("Destroyed texture #") + std::to_string(counter));

        counter++;
    }

    if (log != nullptr)
        log->print(typeid(this).name(), "Calling parent destructor...");
}

SDL_Texture *const Fruit::getTexture() const
{
    return textures.at(
        getRandom<int>(0, textures.size() - 1));
}

bool Fruit::renderTexture()
{
    if (SDL_RenderCopy(
            renderer, this->getTexture(),
            NULL, this->texturePropierties) != 0)
    {
        this->log->print(typeid(this).name(),
                         "Failed to load texture",
                         Logging::InfoType::ERROR);

        return false;
    }

    return true;
}