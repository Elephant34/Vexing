#include <iostream>
#include "Platform.h"

Platform::Platform(sf::Vector2f position)
{
    // Sets up the sprite texture
    if (!platform_texture.loadFromFile("Images/Platform0.png"))
    {
        std::cout << "Error loading texture";
    }
    platform_texture.setSmooth(true);

    setTexture(platform_texture);

    setPosition(position);
}
