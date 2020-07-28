#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 700), "Vexing");

    // clock to get the time between frames
    sf::Clock frame_clock;

    // Stores the delta time between frames
    sf::Time elapsed;

    // Stores object vecotrs for collision
    std::vector<RigidBody> platform_vector;

    // Some test objects
    Platform test_platform(sf::Vector2f(300.f, 300.f));
    platform_vector.push_back(test_platform);
    Player test_player(sf::Vector2f(300.f, 100.f));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        elapsed = frame_clock.restart();
        
        // Updates all objects
        test_platform.update(elapsed);
        test_player.update(elapsed, platform_vector);

        window.clear(sf::Color::Black);

        // Draw the test objects
        window.draw(test_platform);
        window.draw(test_player);

        window.display();

    }

    return 0;
}