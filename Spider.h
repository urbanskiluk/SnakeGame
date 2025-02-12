#ifndef SNAKE_SPIDER_H
#define SNAKE_SPIDER_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <stdlib.h>
#include <time.h>
#include "Enemy.h"

class Spider : public Enemy
{

public:
    Spider(float xCor, float yCor);

    void updatePositionOfEnemy(sf::RenderWindow &window, int width, int height, float elapsed) override;

    float getXCordOfEnemy() override;
    float getYCordOfEnemy() override;
    sf::Sprite getSpriteOfEnemy() override;


private:
    sf::Texture textureOfSpider;
    sf::Sprite spider;

    float xCordOfSpider{300};
    float yCordOfSpider{300};
    int steps{0};
    int counterOfSteps{0};
    const float speedOfSpider{100.f};

    void updateDirectionOfSpider(float elapsed);

    void generateNewDirection();

    void generateNumbOfSteps();

    enum class Direction
    {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    Direction directionOfSpider;
};


#endif //SNAKE_SPIDER_H
