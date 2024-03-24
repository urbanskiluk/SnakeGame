#include "Grape.h"

void Grape::loadTexture()
{
    textureOfGrape.loadFromFile("grape.png");
    grape.setTexture(textureOfGrape);
}

void Grape::generateNewPosition(int wH, int wW, Obstacles &obstacles)
{
    xOfGrape = (rand() % wW);
    yOfGrape = (rand() % wH);

    if ((xOfGrape >= obstacles.xCordOfFence - 20 && xOfGrape <= obstacles.xCordOfFence + 140 &&
         yOfGrape >= obstacles.yCordOfFence - 20 && yOfGrape <= obstacles.yCordOfFence + 60) ||
        (xOfGrape >= obstacles.xCordOfStone - 20 && xOfGrape <= obstacles.xCordOfStone + 50 &&
         yOfGrape >= obstacles.yCordOfStone - 20 && yOfGrape <= obstacles.yCordOfStone + 50))
    {
        generateNewPosition(wH, wW, obstacles);
    }

    if (xOfGrape < 20)
    {
        xOfGrape = xOfGrape + 20;
    }
    if (yOfGrape < 20)
    {
        yOfGrape = yOfGrape + 20;

    }
    if (xOfGrape > wW - 20)
    {
        xOfGrape = xOfGrape - 20;
    }
    if (yOfGrape > wH - 20)
    {
        yOfGrape = yOfGrape - 20;
    }
}

void Grape::updatePositionOfFood()
{
    grape.setPosition(xOfGrape, yOfGrape);
}

float Grape::getXfoodPosition()
{
    return xOfGrape;
}

float Grape::getYfoodPosition()
{
    return yOfGrape;
}

sf::Sprite Grape::getSprite()
{
    return grape;
}

int Grape::scoreOfFood()
{
    return scoreOfGrape;
}
