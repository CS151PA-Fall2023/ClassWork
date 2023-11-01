#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    ~Game(){};

    void handleInput();
    void update();
    void render();
    bool isDone() const;

private:
    sf::RenderWindow mWindow;
    bool mIsDone;

    sf::Texture mTextureTile;
    sf::CircleShape mCherryPlant;
    sf::Vector2f mIncrement;

    void moveCherry();
   
};


#endif