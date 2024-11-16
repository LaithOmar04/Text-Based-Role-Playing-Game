#ifndef ATTACKITEM
#define ATTACKITEM

#include "item.h"

class attackItem : public Item {
    public:
    attackItem(string n);
    void useAbility(Character* player);
};



#endif