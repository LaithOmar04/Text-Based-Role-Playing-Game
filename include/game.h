#ifndef GAME_H
#define GAME_H

#include "../include/game.h"
#include "../include/character.h"
#include <iostream>

using namespace std;

class Game {
   public:
       void startGame();
       Character* createCharacter(string& name, string& gender, int age, string& species);
   private:
       string difficulty;
};


#endif
