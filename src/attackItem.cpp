#include "../include/attackItem.h"
#include <iostream>

attackItem::attackItem(string n){
    name = n;
    ability = "attack";
    strength = 10;
}

void attackItem::useAbility(Character* player){
    cout << "Using " << ability << " item!" << endl;
    player->setAttack(player->getAttack() + strength);
}