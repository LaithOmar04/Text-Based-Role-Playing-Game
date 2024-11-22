#include <iostream>
#include "../include/rewardSystem.h"
#include "../include/attackItem.h"
#include "../include/defenseItem.h"
#include "../include/healthItem.h"

using namespace std;

void RewardSystem::displayRewards() {
    cout << "1. Attack Potion, 2. Defense Potion, 3. Health Potion" << endl;
}
void RewardSystem::rewardItem(Character* player, int index) {
    if(index == 1) {
        player->addItem(new attackItem("Attack Potion"));
    }
    else if(index == 2) {
        player->addItem(new defenseItem("Defense Potion"));
    }
    else {
        player->addItem(new healthItem("Health Potion"));
    }
}