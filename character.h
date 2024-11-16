#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
private:
    string name;
    int age;
    int level;
    string gender;
    string species;
    int xp;
    int attack;
    int hp;
    int defense;

public:
    Character();
    Character( const string& name, int age, const string& gender, const string& species);

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

    // Functions for initializing each species
    void initializeDragon();
    void initializeDemon();
    void initializeAngel();
    void initializeWizard();

    // Print character info
    void printCharacterInfo() const;
};

#endif // CHARACTER_H
