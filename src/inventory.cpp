#include "../include/inventory.h"
#include "../include/character.h"
#include "../include/item.h"
#include <iostream>

Inventory::~Inventory(){
    for (int i=0; i < inventory.size(); ++i){
        delete inventory[i];
    }
}

void Inventory::addItem(Item* item) {
    this->inventory.push_back(item);
}
    
void Inventory::useItem(Character* player, int index) {
    this->inventory[index]->useAbility(player);
    this->inventory.erase(this->inventory.begin() + index);
}
    
void Inventory::displayItems() {
    if(this->inventory.size() == 0) {
        cout << "Inventory is empty!" << endl;

        return;
    }

    for(int i = 0; i < this->inventory.size(); ++i) {
        cout << (i + 1) << ". " << this->inventory[i]->getName() << " ";
    }

    cout << endl;
}

Item* Inventory::getItem(int index) {
    return this->inventory[index];
}

int Inventory::getSize() {
    return this->inventory.size();
}