#include <string>

using std::string;

class Enemy {
   public:
       Enemy() : name("NoName"), type("NoType"), gender("NoGender") {};
       Enemy(string name_, string type_, string gender_) : name(name_), type(type_), gender(gender_) {};
       void initRandEnemy();
       void initMiniBoss();
       void initFinalBoss();
       int getHealth();
       void takeDamage(int damage);
       void displayStatus();
   private:
       string name;
       string type;
       string gender;
       int level;
       int health;
       int attack;
       int defence;
};
