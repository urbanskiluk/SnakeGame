#include "LevelUpdater.h"
#include "Apple.h"
#include "Banana.h"
#include "Orange.h"
#include "Enemy.h"
#include "Spider.h"
#include "Grape.h"
#include <memory>

LevelUpdater::LevelUpdater()
{
    std::vector<std::shared_ptr<Food>> foods;
    std::vector<std::shared_ptr<Enemy>> enemies;
    auto spider0 = std::make_shared<Spider>(10, 200);
    enemies.push_back(spider0);
    auto apple = std::make_shared<Apple>();
    foods.push_back(apple);
    auto grape = std::make_shared<Grape>();
    foods.push_back(grape);
    LevelParameters level1(50, foods, enemies, 5,1.f );
    levels[1] = level1;

    auto apple1 = std::make_shared<Apple>();
    foods.push_back(apple1);
    LevelParameters level2(48, foods, enemies, 15,1.f );
    levels[2] = level2;

    auto orange = std::make_shared<Orange>();
    foods.push_back(orange);
    LevelParameters level3(45, foods, enemies, 30,1.f );
    levels[3] = level3;

    auto spider = std::make_shared<Spider>(100, 250);
    enemies.push_back(spider);
    auto orange1 = std::make_shared<Orange>();
    foods.push_back(orange1);
    LevelParameters level4(40, foods, enemies, 50,1.f );
    levels[4] = level4;

    foods.erase(foods.begin());
    auto banana = std::make_shared<Banana>();
    foods.push_back(banana);
    LevelParameters level5(30, foods, enemies, 70,1.f );
    levels[5] = level5;

    auto banana1 = std::make_shared<Banana>();
    foods.push_back(banana1);
    LevelParameters level6(25, foods, enemies, 100,1.f );
    levels[6] = level6;

    auto orange2 = std::make_shared<Orange>();
    foods.push_back(orange2);
    LevelParameters level7(24, foods, enemies, 150,1.f );
    levels[7] = level7;

    auto spider1 = std::make_shared<Spider>(20, 250);
    enemies.push_back(spider1);
    auto banana2 = std::make_shared<Banana>();
    foods.push_back(banana2);
    LevelParameters level8(21, foods, enemies, 250,1.f );
    levels[8] = level8;

    auto banana3 = std::make_shared<Banana>();
    foods.push_back(banana3);
    LevelParameters level9(18, foods, enemies, 350,1.f );
    levels[9] = level9;

    auto spider2 = std::make_shared<Spider>(100, 250);
    enemies.push_back(spider2);
    auto banana4 = std::make_shared<Banana>();
    foods.push_back(banana4);
    LevelParameters level10(15, foods, enemies, 500,1.f );
    levels[10] = level10;
}

LevelParameters LevelUpdater::getLevelParameters(int level)
{
    return levels[level];
}

std::vector<std::shared_ptr<Food>> LevelUpdater::prepareFood(int level)
{
    LevelParameters levelParameters = levels[level];

    std::vector<std::shared_ptr<Food>> foodToEat;

    for (int i = 0; i < levelParameters.appleAmount; i++)
    {
        auto appleToEat = std::make_shared<Apple>();
        foodToEat.push_back(appleToEat);

    }
    for (int i = 0; i < levelParameters.grapeAmount; i++)
    {
        auto grapeToEat = std::make_shared<Grape>();
        foodToEat.push_back(grapeToEat);

    }
    for (int i = 0; i < levelParameters.bananaAmount; i++)
    {
        auto bananaToEat = std::make_shared<Banana>();
        foodToEat.push_back(bananaToEat);

    }
    for (int i = 0; i < levelParameters.orangeAmount; i++)
    {
        auto orangeToEat = std::make_shared<Orange>();
        foodToEat.push_back(orangeToEat);

    }
    return foodToEat;


}
