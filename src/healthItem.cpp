#include "../include/healthItem.h"
#include <iostream>

healthItem::healthItem(string n){
    name = n;
    ability = "health";
    strength = 10;
}

void healthItem::useAbility(Character* player){
    cout << "Using " << ability << " item!" << endl;
    player->setHP(player->getHP() + strength);
}