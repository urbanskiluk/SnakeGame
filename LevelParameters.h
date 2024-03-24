#ifndef SNAKE_LEVELPARAMETERS_H
#define SNAKE_LEVELPARAMETERS_H


#include <vector>
#include <memory>
#include "Food.h"
#include "Enemy.h"

class LevelParameters
{
public:
    LevelParameters()
    {}

    LevelParameters(int speedOfGamePlay, std::vector<std::shared_ptr<Food>> &foods, std::vector<std::shared_ptr<Enemy>> &enemies, int scoreToLevelUp, float speedOfSpider);

    std::vector<std::shared_ptr<Food>> foods;
    std::vector<std::shared_ptr<Enemy>> enemies;
    int speedOfGamePlay{50};
    float speedOfSpider{1.f};
    int appleAmount{0};
    int orangeAmount{0};
    int bananaAmount{0};
    int grapeAmount{0};
    int spidersAmount{0};
    int scoreToLevelUp{0};


};


#endif //SNAKE_LEVELPARAMETERS_H
