#include "../include/finalBoss.h"

using namespace std;
FinalBoss::FinalBoss(){
    initialize();
}

void FinalBoss::initialize() {
    type = "Final Boss";
    hp = 600;
    attack = 50;
    defense = 40;
    level = 100;
}