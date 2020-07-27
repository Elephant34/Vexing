#pragma once
#include "RigidBody.h"
#include <SFML/Graphics.hpp>

class Player :
    public RigidBody
{
public:
    sf::Texture player_texture;

    // Constructor
    Player(sf::Vector2f position);
};

