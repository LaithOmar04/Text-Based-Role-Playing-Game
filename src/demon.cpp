#include "../include/demon.h"

using namespace std;
Demon::Demon(){
    initialize();
}

void Demon::initialize(){
    species = "Demon";
    attack = 15;  // Base 10 + 5 for Demon
    defense = 15; // Base 10 + 5 for Demon
    hp = 100;   
    level = 1;
    xp = 0;
    maxHp = 100;
}