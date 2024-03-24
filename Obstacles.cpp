#include "Obstacles.h"

void Obstacles::loadTexturesOfObstacles()
{
    textureOfFence.loadFromFile("fence.png");
    fence.setTexture(textureOfFence);
    textureOfStone.loadFromFile("stone.png");
    stone.setTexture(textureOfStone);

    setPositionOfObstacles();

}

void Obstacles::setPositionOfObstacles()
{
    fence.setPosition(xCordOfFence,yCordOfFence);
    stone.setPosition(xCordOfStone,yCordOfStone);
}

sf::Sprite Obstacles::getFenceSprite()
{
    return fence;
}

sf::Sprite Obstacles::getStoneSprite()
{
    return stone;
}
