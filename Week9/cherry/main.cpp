#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>

int main()
{
    Game game;

    // Time step here isn’t the visible frame rate anymore
    // Just the granularity we use to update the game
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f/ 30.f);

    sf::Clock clock; // starts the clock
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(!game.isDone())
    {
        timeSinceLastUpdate += clock.restart();
 
        game.handleInput();  
        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            game.update();
        }

        game.render();
    }

    return 0;
}


/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing sprite.");

    sf::Texture textureTile;
    textureTile.loadFromFile("rpg_textures.png");

    //sf::Sprite cherryPlant(textureTile);
    sf::CircleShape cherryPlant(31);
    cherryPlant.setTexture(&textureTile);

    cherryPlant.setTextureRect(sf::IntRect(64, 32, 62, 62));
    cherryPlant.setOrigin(64.f / 2.f, 62.f / 2.f);
    
    sf::Vector2f increment(0.4f, 0.4f); // (x, y) axis

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if ((cherryPlant.getPosition().x + (64 / 2) > window.getSize().x && 
             increment.x > 0) ||
            (cherryPlant.getPosition().x - (64 / 2) < 0 && increment.x < 0))
        {
            // Reverse the direction on the X axis
            increment.x = -1*increment.x;
        }

        if ((cherryPlant.getPosition().y + (62 / 2) > window.getSize().y && 
             increment.y > 0) ||
            (cherryPlant.getPosition().y - (62 / 2) < 0 && increment.y < 0))
        {
            // Reverse the direction on the Y axis.
            increment.y = -increment.y;
        }

        cherryPlant.setPosition(
            cherryPlant.getPosition().x + increment.x,
            cherryPlant.getPosition().y + increment.y);

        window.clear(sf::Color::Black);
        window.draw(cherryPlant);

        window.display();
    }

    return 0;
}
*/
