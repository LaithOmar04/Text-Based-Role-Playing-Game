#include "item.h"
#include <iostream>
using namespace std;

void Item::displayItem(){
    cout << "This is a " << name << endl;
    cout << "It improves your " << ability << " by " << strength << "!" << endl;
}

string Item::getName(){
    return name;
}

string Item::getAbility(){
    return ability;
}

int Item::getStrength(){
    return strength;
}