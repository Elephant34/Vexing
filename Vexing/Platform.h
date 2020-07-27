#pragma once
#include <SFML/Graphics.hpp>
#include "RigidBody.h"

class Platform :
    public RigidBody
{
public:
    sf::Texture platform_texture;

    // Constructer
    Platform(sf::Vector2f position);
};

