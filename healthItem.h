#ifndef HEALTHITEM
#define HEALTHITEM

#include "item.h"
#include "character.h"
using namespace std;

class healthItem : public Item  {
    public:
    healthItem(string n);
    void useAbility(Character* player);
};



#endif