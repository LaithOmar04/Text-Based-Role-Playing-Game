
#ifndef BATTLESYSTEM
#define BATTLESYSTEM

#include "character.h"
#include "enemy.h"

class battleSystem {
   public:
       void startBattle(Character* player, Enemy* enemy);
   private:
       Character* player;
       Enemy* enemy;
};

#endif
