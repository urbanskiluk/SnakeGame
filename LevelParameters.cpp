#include "LevelParameters.h"

LevelParameters::LevelParameters(int speedOfGamePlay, std::vector<std::shared_ptr<Food>> &foods,
                                 std::vector<std::shared_ptr<Enemy>> &enemies, int scoreToLevelUp, float speedOfSpider)
{
    this->foods = foods;
    this->enemies = enemies;
    this->speedOfGamePlay = speedOfGamePlay;
    this->spidersAmount = spidersAmount;
    this->scoreToLevelUp = scoreToLevelUp;
    this->speedOfSpider = speedOfSpider;


}