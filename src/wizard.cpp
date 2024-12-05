#include "../include/wizard.h"

using namespace std;
Wizard::Wizard(){
    initialize();
}

void Wizard::initialize() {
    species = "Wizard";
    attack = 15;  // Base 10 + 5 for Wizard
    defense = 10;
    hp = 110;     // Base 100 + 10 for Wizard
    level = 1;
    xp = 0;
    maxHp = 110;
}