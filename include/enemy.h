#ifndef ENEMY_H
#define ENEMY_H

#include <string>

using std::string;

class Enemy {
  public:
      Enemy() : name("NoName"), type("NoType"), gender("NoGender") {};

      string getName() const;
      int getLevel() const;
      string getGender() const;
      int getAttack() const;
      int getHP() const;
      int getDefense() const;
      string getType() const;
  
      void setLevel(int level);
      void setAttack(int attack);
      void setHP(int hp);
      void setDefense(int defense);
      void setName(string name);
      void setGender(string gender);
      void setType(string type);


      void printEnemyInfo() const;
      virtual void initialize() = 0;


  protected:
      string name;
      string type;
      string gender;
      int level;
      int hp;
      int attack;
      int defense;
};

#endif