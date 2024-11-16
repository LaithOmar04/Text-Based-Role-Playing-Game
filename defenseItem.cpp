#include "defenseItem.h"
#include <iostream>

defenseItem::defenseItem(string n){
    name = n;
    ability = "defense";
    strength = 10;
}

void defenseItem::useAbility(Character* player){
    cout << "Using " << ability << " item!" << endl;
    player->setDefense(player->getDefense() + strength);
}