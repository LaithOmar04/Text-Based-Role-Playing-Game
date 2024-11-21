#ifndef DEFENSEITEM
#define DEFENSEITEM

#include "item.h"

class defenseItem : public Item {
    public:
    defenseItem(string n);
    void useAbility(Character* player);
};



#endif