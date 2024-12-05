#include "../include/character.h"
#include "../include/inventory.h"
#include "../include/item.h"
#include <iostream>

using namespace std;

// Default constructor
Character::Character()
    : name(""), age(0), level(1), gender(""), species(""),
      xp(0), attack(10), hp(100), defense(10), maxHp(100) {}

// Getters
string Character::getName() const { return name; }
int Character::getAge() const { return age; }
int Character::getLevel() const { return level; }
string Character::getGender() const { return gender; }
string Character::getSpecies() const { return species; }
int Character::getXP() const { return xp; }
int Character::getAttack() const { return attack; }
int Character::getHP() const { return hp; }
int Character::getDefense() const { return defense; }
bool Character::atFullHealth() {return this->hp == this->maxHp;}

// Setters
void Character::setLevel(int level) { this->level = level; }
void Character::setXP(int xp) { this->xp = xp; }
void Character::setAttack(int attack) { this->attack = attack; }
void Character::setHP(int hp) { 
    this->hp = hp;
    if(this->maxHp < hp) {
        this->maxHp = hp;
    }
 }
void Character::setDefense(int defense) { this->defense = defense; }
void Character::setName(string name) { this->name = name; }
void Character::setAge(int age) { this->age = age; }
void Character::setGender(string gender) { this->gender = gender; }

void Character::addItem(Item* i){
    inventory.addItem(i);
}

void Character::useItem(int i){
    inventory.useItem(this, i);
}

void Character::displayInventory(){
    inventory.displayItems();
}
void Character::levelUp(){
    level += 1;
    xp = xp - 100;
    attack += 20;
    hp += 20;
}

void Character::rejuvinate() {
    this->hp = this->maxHp;
}

// Print character info
void Character::printCharacterInfo() const {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Level: " << level << endl;
    cout << "Gender: " << gender << endl;
    cout << "Species: " << species << endl;
    cout << "XP: " << xp << endl;
    cout << "Attack: " << attack << endl;
    cout << "HP: " << hp << endl;
    cout << "Defense: " << defense << endl;
}

int Character::getInventorySize() {
   return inventory.getSize();
}

