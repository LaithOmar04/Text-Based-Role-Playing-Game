#include "../include/game.h"
#include "../include/dragon.h"
#include "../include/demon.h"
#include "../include/angel.h"
#include "../include/wizard.h"
#include "../include/battleSystem.h"
#include "../include/randomEnemy.h"
#include "../include/miniBoss.h"


void Game::startGame(string difficulty) {
   this->difficulty = difficulty; // FIXME: Implement difficulty
   cout << "Welcome to the game! The difficulty is set to " << difficulty << "." << endl;


   // Character Creation
   string name, gender, species;
   int age;


   cout << "Enter your character's name: ";
   cin >> name;


   cout << endl << "Enter your character's gender: ";
   cin >> gender;


   cout << endl << "Enter your character's age: ";
   cin >> age;


   cout << endl << "Enter your character's species: ";
   cin >> species;


   Character* player = createCharacter(name, gender, age, species);
   cout << endl << "Character created! Welcome, " << player->getName() << "." << endl;


   battleSystem battleSystem;


   // FIXME: Final boss not implemented
   while (player->getHP() > 0) {
       cout << "You move forward on your journey..." << endl;


       // Choices
       cout << "Do you want to: " << endl;
       cout << "1. Fight random enemies to gain experience." << endl;
       cout << "2. Challenge a Mini-Boss for greater rewards. " << endl;
       cout << "Enter your choice (1 or 2): ";
       int choice;
       cin >> choice;


       if (choice == 1) {
           cout << "You encounter a random enemy!" << endl;
           RandomEnemy* randomEnemy = new RandomEnemy(); // Random level between 1 and 5
           battleSystem.startBattle(player, randomEnemy, 1); // Escape chance is 50%
           delete randomEnemy;
       } else if (choice == 2) {
           cout << "A Mini-Boss appears!" << endl;
           MiniBoss* miniBoss = new MiniBoss(); // Random level between 6 and 8
           battleSystem.startBattle(player, miniBoss, 0); // No escape for mini-boss fights
           delete miniBoss;
       } else {
           cout << "Invalid choice. You hesitate and lose time.\n";
           continue; // Skip this loop iteration
       }

       // Check if the player is still alive
       if (player->getHP() <= 0) {
           cout << "\nYour health has dropped to zero. You have been defeated.<< endl << Game Over." << endl;
           break;
       }
   }

   delete player;
}


Character* Game::createCharacter(string& name, string& gender, int age, string& species) {
   if (species == "Dragon") {
       Dragon* character = new Dragon();
       character->setName(name);
       character->setGender(gender);
       character->setAge(age);
       return character;
   }
   else if (species == "Demon") {
       Demon* character = new Demon();
       character->setName(name);
       character->setGender(gender);
       character->setAge(age);
       return character;
   }
   else if (species == "Angel") {
       Angel* character = new Angel();
       character->setName(name);
       character->setGender(gender);
       character->setAge(age);
       return character;
   }
   else if (species == "Wizard") {
       Wizard* character = new Wizard();
       character->setName(name);
       character->setGender(gender);
       character->setAge(age);
       return character;
   }
   return nullptr;
}


