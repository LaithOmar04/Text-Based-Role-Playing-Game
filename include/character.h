#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "inventory.h"
#include "item.h"

using namespace std;

class Character {
protected:
    string name;
    int age;
    int level;
    string gender;
    string species;
    int xp;
    int attack;
    int hp;
    int defense;
    Inventory inventory;

public:
    Character();

    string getName() const;
    int getAge() const;
    int getLevel() const;
    string getGender() const;
    std::string getSpecies() const;
    int getXP() const;
    int getAttack() const;
    int getHP() const;
    int getDefense() const;

   
    void setLevel(int level);
    void setXP(int xp);
    void setAttack(int attack);
    void setHP(int hp);
    void setDefense(int defense);
    void setName(string name);
    void setAge(int age);
    void setGender(string gender);
    void addItem(Item* i);
    void useItem(int i);
    void displayInventory();

    virtual void initialize() = 0;

    // Print character info
    void printCharacterInfo() const;
};

#endif // CHARACTER_H
