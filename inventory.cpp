#include "inventory.h"
#include <iostream>

void Inventory::addItem(Item* item) {
    this->inventory.push_back(item);
}
    
void Inventory::useItem(Character* player, int index) {
    this->inventory[index - 1]->useAbility(player);
}
    
void Inventory::displayItems() {
    for(int i = 0; i < this->inventory.size(); ++i) {
        cout << (i + 1) << ". " << this->inventory[i]->getName() << " ";
    }
}