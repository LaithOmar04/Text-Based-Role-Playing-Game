#include "../include/angel.h"

using namespace std;
Angel::Angel(){
    initialize();
}

void Angel::initialize(){
    species = "Angel";
    attack = 10;  
    defense = 10; 
    hp = 130;     // Base 100 + 30 for Angel
    level = 1;
    xp = 0;
    maxHp = 130;
    
}
