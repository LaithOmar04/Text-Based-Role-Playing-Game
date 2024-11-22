#include "../include/enemy.h"
#include <iostream>

using namespace std;

string Enemy::getName() const {return this->name;}
int Enemy::getHP() const {return this->hp;}
string Enemy::getType() const {return this->type;}
int Enemy::getAttack() const {return this->attack;}
string Enemy::getGender() const {return this->gender;}
int Enemy::getDefense() const {return this->defense;}
int Enemy::getLevel() const {return this->level;}

void Enemy::setName(string name) {this->name = name;}
void Enemy::setHP(int hp) {this->hp = hp;}
void Enemy::setType(string type) {this->type = type;}
void Enemy::setAttack(int attack) {this->attack = attack;}
void Enemy::setGender(string gender) {this->gender = gender;}
void Enemy::setDefense(int defense) {this->defense = defense;}
void Enemy::setLevel(int level) {this->level = level;}

void Enemy::printEnemyInfo() const {
   cout << "Name: " << name << endl;
   cout << "Type: " << type << endl;
   cout << "Level: " << level << endl;
   cout << "Gender: " << gender << endl;
   cout << "Attack: " << attack << endl;
   cout << "HP: " << hp << endl;
   cout << "Defense: " << defense << endl;
}