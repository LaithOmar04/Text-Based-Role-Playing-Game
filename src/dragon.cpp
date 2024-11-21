#include "../include/dragon.h"

using namespace std;
Dragon::Dragon() {
    initialize();
}

void Dragon::initialize() {
    species = "Dragon";
    attack = 20;  // Base 10 + 10 for Dragon
    defense = 10; 
    hp = 100; 
    level = 1;
    xp = 0;
}