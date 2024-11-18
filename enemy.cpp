#include "enemy.h"
#include <iostream>

using std::rand;
using std::cout;
using std::endl;

void Enemy::initRandEnemy() {
   health = 100 - (rand() % 10);
   attack = 15 - (rand() % 5);
   defence = 10 - (rand() % 5);
}
void Enemy::initMiniBoss() {
   health = 300 - (rand() % 10);
   attack = 35 - (rand() % 7);
   defence = 30 - (rand() % 10);
}
void Enemy::initFinalBoss() {
   health = 600;
   attack = 50;
   defence = 40;
}
int Enemy::getHealth() {
   return health;
}
void Enemy::takeDamage(int damage) { // becomes 0 if negative
   health -= damage;
   if (health < 0) {
       health = 0;
   }
}
void Enemy::displayStatus() {
   cout << name << "'s Status:" << endl;
   cout << "Health Remaining: " << health << endl;
   cout << "Attack: " << attack << endl;
   cout << "Defence: " << defence << endl;
}
