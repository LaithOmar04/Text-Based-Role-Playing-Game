#include "../include/randomEnemy.h"

using namespace std;
RandomEnemy::RandomEnemy(){
    initialize();
}

void RandomEnemy::initialize() {
    type = "Random Enemy";
    hp = 100 - (rand() % 10);
    attack = 15 - (rand() % 5);
    defense = 10 - (rand() % 5);
    level = 1;
}