

#ifndef SNAKE_ENEMY_H
#define SNAKE_ENEMY_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Enemy
{
public:

    virtual void updatePositionOfEnemy(sf::RenderWindow &window, int width, int height, float elapsed) = 0;

    virtual float getXCordOfEnemy() = 0;

    virtual float getYCordOfEnemy() = 0;

    virtual sf::Sprite getSpriteOfEnemy() = 0;
};


#endif //SNAKE_ENEMY_H
