#include "../include/miniBoss.h"

using namespace std;
MiniBoss::MiniBoss(){
    initialize();
}

void MiniBoss::initialize() {
    type = "Mini Boss";
    hp = 300 - (rand() % 10);
    attack = 35 - (rand() % 7);
    defense = 30 - (rand() % 10);
    level = 1;
}