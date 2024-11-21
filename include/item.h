#ifndef ITEM
#define ITEM

#include <string>
#include "character.h"

class Character;

class Item {
protected:
    std::string name;
    std::string ability;
    int strength;
public:
    void displayItem();
    virtual void useAbility(Character* player) = 0;
    std::string getName();
    std::string getAbility();
    int getStrength();
};

#endif