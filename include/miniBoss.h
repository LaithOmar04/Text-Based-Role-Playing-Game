#ifndef MINIBOSS_H
#define MINIBOSS_H

#include "../include/enemy.h"
#include <iostream>

using namespace std;

class MiniBoss : public Enemy {
    public:
    MiniBoss();
    void initialize();
};

#endif