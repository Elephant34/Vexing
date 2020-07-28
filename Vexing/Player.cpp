#include <iostream>
#include "Player.h"

Player::Player(sf::Vector2f position)
{
    // Sets up the sprite texture
    if (!player_texture.loadFromFile("Images/Player.png")) 
    {
        std::cout << "Error loading texture";
    }
    player_texture.setSmooth(true);

    setTexture(player_texture);

    setPosition(position);

    // Sets the player to be non-static so will fall under gravity
    is_static = false;
}