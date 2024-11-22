#ifndef REWARDSYSTEM
#define REWARDSYSTEM

#include <string>
#include "character.h"
#include "item.h"

class RewardSystem {

    public:
    void displayRewards();
    void rewardItem(Character* player, int index);

};

#endif