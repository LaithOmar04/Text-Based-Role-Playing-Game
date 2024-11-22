#ifndef RANDOMENEMY_H
#define RANDOMENEMY_H

#include "../include/enemy.h"
#include <iostream>

using namespace std;

class RandomEnemy : public Enemy {
    public:
    RandomEnemy();
    void initialize();
};

#endif