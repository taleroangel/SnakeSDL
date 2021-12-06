#include "Scenario.hpp"
#include "../Logging/Logging.hpp"
#include <typeinfo>

Scenario::Scenario(SDL_Renderer *renderer, std::string filename,
                   Logging *logs) noexcept(false)
    : Texture(renderer, filename, logs)
{
    if (log != nullptr)
        log->print(typeid(this).name(), "Parent constructor just ended...");
}

Scenario::~Scenario()
{
    if (log != nullptr)
        log->print(typeid(this).name(), "Calling parent destructor...");
}

bool Scenario::renderTexture()
{
    for (int i = 0; i < this->scenario_size; i += SPRITE_SIZE)
    {
        for (int j = 0; j < scenario_size; j += SPRITE_SIZE)
        {
            this->setCoordinates(i, j);

            if (SDL_RenderCopy(
                    this->renderer, this->texture,
                    NULL, this->texturePropierties) != 0)
            {
                this->log->print(typeid(this).name(),
                                 "Failed to load texture",
                                 Logging::InfoType::ERROR);

                return false;
            }
        }
    }

    return true;
}