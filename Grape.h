#ifndef SNAKE_GRAPE_H
#define SNAKE_GRAPE_H


#include <time.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Food.h"

class Grape : public Food
{
public:
    Grape()
    {
        srand(time(NULL));
    }

    void loadTexture() override;

    void generateNewPosition(int wH, int wW , Obstacles &obstacles) override;

    void updatePositionOfFood() override;

    float getXfoodPosition() override;

    float getYfoodPosition() override;

    sf::Sprite getSprite() override;

    int scoreOfFood() override;

    float xOfGrape{100};
    float yOfGrape{100};
    sf::Sprite grape;

private:
    sf::Texture textureOfGrape;

    int scoreOfGrape{4};

};


#endif //SNAKE_GRAPE_H
