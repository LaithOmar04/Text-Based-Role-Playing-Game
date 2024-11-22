#ifndef FINALBOSS_H
#define FINALBOSS_H

#include "../include/enemy.h"
#include <iostream>

using namespace std;

class FinalBoss : public Enemy {
    public:
    FinalBoss();
    void initialize();
};

#endif