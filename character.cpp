#include "character.h"
#include <iostream>

using namespace std;

// Default constructor
Character::Character()
    : name(""), age(0), level(1), gender(""), species(""),
      xp(0), attack(10), hp(100), defense(10) {}

// constructor
Character::Character( const string& name, int age, const string& gender, const string& species)
    : name(name), age(age), level(1), gender(gender), species(species),
      xp(0), attack(10), hp(100), defense(10) {
    // Initialize stats based on species
    if (species == "Dragon") {
        initializeDragon();
    } 
    else if (species == "Demon") {
        initializeDemon();
    } 
    else if (species == "Angel") {
        initializeAngel();
    } 
    else if (species == "Wizard") {
        initializeWizard();
    }
}

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

// Setters
void Character::setLevel(int level) { this->level = level; }
void Character::setXP(int xp) { this->xp = xp; }
void Character::setAttack(int attack) { this->attack = attack; }
void Character::setHP(int hp) { this->hp = hp; }
void Character::setDefense(int defense) { this->defense = defense; }

void Character::initializeDragon() {
    attack = 20;  // Base 10 + 10 for Dragon
    defense = 10; 
    hp = 100;     
}


void Character::initializeDemon() {
    attack = 15;  // Base 10 + 5 for Demon
    defense = 15; // Base 10 + 5 for Demon
    hp = 100;     
}

void Character::initializeAngel() {
    attack = 10;  
    defense = 10; 
    hp = 130;     // Base 100 + 30 for Angel
}

void Character::initializeWizard() {
    attack = 15;  // Base 10 + 5 for Wizard
    defense = 10;
    hp = 110;     // Base 100 + 10 for Wizard
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