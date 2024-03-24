#ifndef SNAKE_LEVELUPDATER_H
#define SNAKE_LEVELUPDATER_H
#include <map>
#include "LevelParameters.h"
#include "Food.h"
#include <vector>
#include <memory>

class LevelUpdater
{
public:
    LevelUpdater();
    LevelParameters getLevelParameters(int level);

    std::vector<std::shared_ptr<Food>> prepareFood(int level);
private:
    std::map<int,LevelParameters>levels;

};


#endif //SNAKE_LEVELUPDATER_H
