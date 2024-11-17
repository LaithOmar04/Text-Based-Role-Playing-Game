#ifndef INVENTORY
#define INVENTORY

#include "item.h"
#include <vector>

using namespace std;

class Inventory {
    private:
    vector<Item*> inventory;

    public:
    void addItem(Item* item);
    void useItem(Character* player, int index);
    Item* getItem(int index);
    void displayItems();
    int getSize();

};

#endif
