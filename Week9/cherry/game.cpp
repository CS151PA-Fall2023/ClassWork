#include "game.h"

/**
 * @brief Construct a new Game:: Game object
 * Setting up the window and graphics using the Game constructor
 * 
 */
Game::Game() : mWindow(sf::VideoMode(640, 480), "Bouncing sprite.")
{
    mTextureTile.loadFromFile("rpg_textures.png");
    mCherryPlant.setRadius(31);
    mCherryPlant.setTexture(&mTextureTile);
    mCherryPlant.setTextureRect(sf::IntRect(64, 32, 62, 62));
    mCherryPlant.setOrigin(62.f / 2.f, 62.f / 2.f);

    mIncrement = sf::Vector2f(1, 1);
    mIsDone = false;
}

/**
 * @brief Handle events from input devices and the window
 * 
 */
void Game::handleInput()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            // Close window button clicked.
            mWindow.close();
        }
    }
}

/**
 * @brief Update objects in the scene
 * 
 */
void Game::update()
{
    moveCherry();
}
/**
 * @brief 
 * 
 */
void Game::moveCherry()
{
    sf::Vector2u winSize = mWindow.getSize();
    int cherryX = 62;
    int cherryY = 62;

    if ((mCherryPlant.getPosition().x + (cherryX / 2) > winSize.x && mIncrement.x > 0) ||
        (mCherryPlant.getPosition().x - (cherryX / 2) < 0 && mIncrement.x < 0))
    {
        // Reverse the direction on X axis
        mIncrement.x = -mIncrement.x;
    }

    if ((mCherryPlant.getPosition().y + (cherryY / 2) > winSize.y && mIncrement.y > 0) ||
        (mCherryPlant.getPosition().y - (cherryY / 2) < 0 && mIncrement.y < 0))
    {
        // Reverse the direction on Y axis.
        mIncrement.y = -mIncrement.y;
    }

    mCherryPlant.setPosition(
        mCherryPlant.getPosition().x + mIncrement.x,
        mCherryPlant.getPosition().y + mIncrement.y);
}
	
/**
 * @brief Render objects from the scene onto the window
 * 
 */
void Game::render()
{
    mWindow.clear(sf::Color::Black);
    mWindow.draw(mCherryPlant);
    mWindow.display();
}
	
/**
 * @brief Check if game is done, right now, we just checked if window is still open
 * 
 * @return true 
 * @return false 
 */
bool Game::isDone() const
{
    return (!mWindow.isOpen() || mIsDone);
}
