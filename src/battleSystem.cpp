#include <iostream>
#include <string>
#include <cstdlib>
#include "../include/battleSystem.h"
using namespace std;


void battleSystem::startBattle(Character* player, Enemy* enemy, int escapeChance) {
   while (player->getHP() > 0 && enemy->getHP() > 0) {
       cout << "\nYou have encountered " << enemy->getName() << "!" << endl;
       cout << "Your HP: " << player->getHP() << " | Enemy HP: " << enemy->getHP() << endl;


       cout << "Choose an action:" << endl;
       cout << "1. Fight" << endl;
       cout << "2. Run" << endl;
       cout << "3. Open Inventory" << endl;


       int choice;
       cin >> choice;


       switch (choice) {
           case 1: { // Fight
               int playerDamage = player->getAttack();
               int enemyDamage = enemy->getAttack();


               enemy->setHP(enemy->getHP() - playerDamage);
               cout << "You dealt " << playerDamage << " damage to the enemy." << endl;


               if (enemy->getHP() > 0) {
                   player->setHP(player->getHP() - enemyDamage);
                   cout << "The enemy dealt " << enemyDamage << " damage to you." << endl;
               } else {
                   cout << "You defeated the enemy!" << endl;
               }


               break;
           }
           case 2: { // Run
               if (escapeChance == 0) {
                   cout << "You successfully ran away!" << endl;
                   return;
               } else {
                   cout << "You failed to escape!" << endl;
                   int enemyDamage = enemy->getAttack();
                   player->setHP(player->getHP() - enemyDamage);
                   cout << "The enemy dealt " << enemyDamage << " damage to you." << endl;
                   return;
               }
               break;
           }
           case 3: { // Open Inventory
               player->displayInventory(); // Display the inventory to the player


               if (player->getInventorySize() == 0) {
                   break;
               }
  
               cout << "Enter the number of the item you want to use (or -1 to cancel): ";
               int itemIndex;
               cin >> itemIndex;


               if (itemIndex == -1) {
                   cout << "You chose not to use any item." << endl;
                   break;
               }                 


               if (itemIndex > 0 && itemIndex <= player->getInventorySize()) {
                   player->useItem(itemIndex - 1); // Use the selected item
               } else {
                   cout << "Invalid item choice. Please try again." << endl;
               }


               break;
           }
           default:
               cout << "Invalid choice. Please try again." << endl;
       }
   }


   if (player->getHP() <= 0) {
       cout << "You have been defeated..." << endl;
   } else if (enemy->getHP() <= 0) {
       cout << "Victory! The enemy has been defeated." << endl;
       player->setXP(player->getXP() + 50);
       if(player->getXP() >= 100){
        cout << "Your traing has paid off you are ready to level up!" << endl;
            player->levelUp();
            cout << "Your level is now " << player->getLevel() << "!" << endl;
       }
       if(player->getHP() < 100) {
            player->setHP(100);
       }
   }
}
