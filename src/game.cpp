#include "../include/game.h"
#include "../include/dragon.h"
#include "../include/demon.h"
#include "../include/angel.h"
#include "../include/wizard.h"
#include "../include/battleSystem.h"
#include "../include/randomEnemy.h"
#include "../include/miniBoss.h"
#include "../include/finalBoss.h"


void Game::startGame() {
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

    int miniCount = 0;
    int runChance;
    // Start of Story
    while (player->getHP() > 0) {
        runChance = rand() % 2;
        if (miniCount == 4) {
            cout << "The Big Boss appears! This is your final challenge!" << endl;
            FinalBoss* bigBoss = new FinalBoss(); 
            battleSystem.startBattle(player, bigBoss, runChance);

            if (player->getHP() > 0) {
                cout << "Congratulations! You defeated the Big Boss and completed the game!" << endl;
            } else {
                cout << "The Big Boss has defeated you." << endl << "Game Over." << endl;
            }

            delete bigBoss;
            break; // End the game after the final boss
        }
        cout << "You move forward on your journey..." << endl;
    
        // Choices
        cout << "Do you want to: " << endl;
        cout << "1. Fight random enemies to gain experience." << endl;
        cout << "2. Challenge a Mini-Boss for greater rewards. " << endl;
        cout << "Enter your choice (1 or 2): ";
        int choice;
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            cout << "You encounter a random enemy!" << endl;
            RandomEnemy* randomEnemy = new RandomEnemy(); 
            battleSystem.startBattle(player, randomEnemy, runChance); // Escape chance is 50%
            delete randomEnemy;
        } else if (choice == 2) {
            cout << "A Mini-Boss appears!" << endl;
            MiniBoss* miniBoss = new MiniBoss();
            battleSystem.startBattle(player, miniBoss, runChance); // No escape for mini-boss fights
            delete miniBoss;
            miniCount++;
        } else {
            cout << "Invalid choice. You hesitate and lose time." << endl;
            continue; // Skip this loop iteration
        }

        // Check if the player is still alive
        if (player->getHP() <= 0) {
            cout <<"Your health has dropped to zero. You have been defeated." << endl << "Game Over." << endl;
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


