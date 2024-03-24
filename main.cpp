#include <iostream>
#include <SFML/Graphics.hpp>
#include "Movement.h"
#include "Apple.h"
#include "Spider.h"
#include "Banana.h"
#include "Orange.h"
#include "Obstacles.h"
#include "LevelUpdater.h"
#include <chrono>
#include <thread>
#include <memory>


int main()
{
    int windowWidth{600};
    int windowHeight{600};
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake");



    LevelUpdater levelUpdater;


    sf::Texture textureOfBody;

    textureOfBody.loadFromFile("partOfSnake.png");

    sf::Sprite body;

    body.setTexture(textureOfBody);

    Obstacles obstacles;
    obstacles.loadTexturesOfObstacles();

    Movement moveOfSnake;

    std::vector<std::shared_ptr<Enemy>> enemies;
    enemies.push_back(std::make_shared<Spider>(100, 400) );

    std::vector<std::shared_ptr<Food> > foodToEat = levelUpdater.prepareFood(1);

    sf::Clock clock;
    float speedOfSpider = 10.f;

    while (window.isOpen())
    {
       float elapsed = clock.restart().asSeconds();

        LevelParameters levelParameters1 = levelUpdater.getLevelParameters(moveOfSnake.level);
        foodToEat = levelParameters1.foods;
        enemies = levelParameters1.enemies;

        sf::Event event;


        for (int i = 0; i < foodToEat.size(); i++)
        {

            foodToEat[i]->loadTexture();
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            moveOfSnake.checkPressedKey(event);

        }

        moveOfSnake.updateLevel(levelParameters1.scoreToLevelUp);
        moveOfSnake.updateMovementDirection();
        moveOfSnake.updatePositionOfSnake(windowWidth, windowHeight);



        for (int i = 0; i < foodToEat.size(); i++)
        {
            if (moveOfSnake.checkIfFoodEaten(foodToEat[i]->getXfoodPosition(), foodToEat[i]->getYfoodPosition(),
                                             foodToEat[i]->scoreOfFood()))
            {
                foodToEat[i]->generateNewPosition(windowWidth, windowHeight, obstacles);

            }
            foodToEat[i]->updatePositionOfFood();
        }

        window.clear();

        for (int i = 0; i < enemies.size(); ++i)
        {
            enemies[i]->updatePositionOfEnemy(window, windowWidth, windowHeight, elapsed);
        }


        for (int i = 0; i < foodToEat.size(); i++)
        {
            window.draw(foodToEat[i]->getSprite());
        }


        for (int i = moveOfSnake.bodyTexture.size() - 1; i >= 0; --i)
        {
            window.draw(moveOfSnake.bodyTexture[i]);
        }



        moveOfSnake.buttonOfGameOverDisplay(window, event, enemies, obstacles);
        window.draw(moveOfSnake.textOfPoints);
        window.draw(obstacles.getFenceSprite());
        window.draw(obstacles.getStoneSprite());


        window.display();

        LevelParameters levelParameters;


        levelParameters = levelUpdater.getLevelParameters(moveOfSnake.level);
        std::chrono::milliseconds timespan(levelParameters.speedOfGamePlay); // or whatever

        std::this_thread::sleep_for(timespan);
    }


    return 0;
}
