#include <iostream>
#include "include/healthItem.h"
#include "include/attackItem.h"
#include "include/defenseItem.h"
#include "include/character.h"
#include "include/demon.h"
#include "include/dragon.h"
#include "include/angel.h"
#include "include/wizard.h"
#include "include/item.h"
#include "include/inventory.h"
#include "include/rewardSystem.h"
#include "include/game.h"

using namespace std;

int main() {
    Game game;
    game.startGame("easy");
    return 0;
}