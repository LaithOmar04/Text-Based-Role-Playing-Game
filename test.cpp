#include "gtest/gtest.h"
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
#include "include/enemy.h"
#include "include/finalBoss.h"
#include "include/miniBoss.h"
#include "include/randomEnemy.h"
#include "include/battleSystem.h"
#include "include/battleSystem.h"
#include <sstream>

TEST(ItemTests, healthItemConstructor){
    healthItem item1("item1");
    EXPECT_EQ(item1.getName(), "item1");
    EXPECT_EQ(item1.getAbility(), "health");
    EXPECT_EQ(item1.getStrength(), 10);
}

TEST(ItemTests, healthItemAbility){
    Character* player1 = new Demon;
    healthItem item1("item1");
    item1.useAbility(player1);
    EXPECT_EQ(player1->getHP(), 110);
}

TEST(ItemTests, attackItemConstructor){
    attackItem item1("item1");
    EXPECT_EQ(item1.getName(), "item1");
    EXPECT_EQ(item1.getAbility(), "attack");
    EXPECT_EQ(item1.getStrength(), 10);
}

TEST(ItemTests, attackItemAbility){
    Character* player1 = new Dragon;
    attackItem item1("item1");
    item1.useAbility(player1);
    EXPECT_EQ(player1->getAttack(), 30);
}

TEST(ItemTests, defenseItemConstructor){
    defenseItem item1("item1");
    EXPECT_EQ(item1.getName(), "item1");
    EXPECT_EQ(item1.getAbility(), "defense");
    EXPECT_EQ(item1.getStrength(), 10);
}

TEST(ItemTests, defenseItemAbility){
    Character* player1 = new Angel;
    defenseItem item1("item1");
    item1.useAbility(player1);
    EXPECT_EQ(player1->getDefense(), 20);
}
// ==================================================

TEST(CharacterTest, demonInitial) {
    Character *demon = new Demon;

    EXPECT_EQ (demon->getSpecies(),"Demon");
    EXPECT_EQ (demon->getAttack(),15);
    EXPECT_EQ (demon->getDefense(),15);
}
TEST(CharacterTest, angelInitial) {
    Character *angel = new Angel;
    
    EXPECT_EQ (angel->getSpecies(),"Angel");
    EXPECT_EQ (angel->getHP(),130);
 
}
TEST(CharacterTest, dragonInitial) {
    Character *dragon = new Dragon;
 
    EXPECT_EQ (dragon->getSpecies(),"Dragon");
    EXPECT_EQ (dragon->getAttack(),20);
 
}
TEST(CharacterTest, wizardInitial) {
    Character *wizard = new Wizard;

    EXPECT_EQ (wizard->getSpecies(),"Wizard");
    EXPECT_EQ (wizard->getAttack(),15);
    EXPECT_EQ (wizard->getHP(),110);
 
}
TEST(CharacterTest, name) {
    Character *dragon = new Dragon;
    dragon->setName("steven");
    EXPECT_EQ (dragon->getName(),"steven");
 
}
TEST(CharacterTest, age) {
    Character *dragon = new Dragon;
    dragon->setAge(19);
    EXPECT_EQ (dragon->getAge(),19);
 
}
TEST(CharacterTest, gender) {
    Character *dragon = new Dragon;
    dragon->setGender("male");
    EXPECT_EQ (dragon->getGender(),"male");
}

// ==================================================

TEST(InventoryTest, addItem) {
    Inventory inventory;
    Item* item = new attackItem("attack potion");
    inventory.addItem(item);

    EXPECT_EQ(inventory.getItem(0)->getName(), "attack potion");
}

TEST(InventoryTest, getItem) {
    Inventory inventory;
    Item* item = new defenseItem("defense potion");
    inventory.addItem(item);

    EXPECT_EQ(inventory.getItem(0)->getAbility(), "defense");
}

TEST(InventoryTest, getSize) {
    Inventory inventory;
    Item* item = new defenseItem("defense potion");
    Item* item2 = new attackItem("attack potion");
    Item* item3 = new healthItem("health potion");

    inventory.addItem(item);
    inventory.addItem(item2);
    inventory.addItem(item3);

    EXPECT_EQ(inventory.getSize(), 3);
}

TEST(InventoryTest, useItem) {
    Character* player = new Wizard;
    Inventory inventory;
    Item* item = new healthItem("health potion");
    inventory.addItem(item);
    inventory.useItem(player, 0);

    EXPECT_EQ(player->getHP(), 120);
}

TEST(InventoryTest, removeItemAfterUse) {
    Character* player = new Angel;
    Inventory inventory;
    Item* item = new healthItem("health potion");
    inventory.addItem(item);
    inventory.useItem(player, 0);

    EXPECT_EQ(inventory.getSize(), 0);
}

TEST(RewardSystemTest, receiveAttackItem) {
    Character* player = new Angel;
    RewardSystem rewards;
    rewards.rewardItem(player, 1);
    player->useItem(0);

    EXPECT_EQ(player->getAttack(), 20);
}

TEST(RewardSystemTest, receiveDefenseItem) {
    Character* player = new Angel;
    RewardSystem rewards;
    rewards.rewardItem(player, 2);
    player->useItem(0);

    EXPECT_EQ(player->getDefense(), 20);
}

TEST(RewardSystemTest, receiveHealthItem) {
    Character* player = new Angel;
    RewardSystem rewards;
    rewards.rewardItem(player, 3);
    player->useItem(0);

    EXPECT_EQ(player->getHP(), 140);
}

TEST(RewardSystemTest, printRewards) {
    RewardSystem rewards;
     // Capture output
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());
    // Call the function
    rewards.displayRewards();
    // Restore the original std::cout buffer
    std::cout.rdbuf(oldCoutBuf);
    // Check output
    std::string expectedOutput = "1. Attack Potion, 2. Defense Potion, 3. Health Potion\n";
    EXPECT_EQ(output.str(), expectedOutput);
}
TEST(CharacterTest, PrintInfoDra) {
    Character *dragon = new Dragon;
    dragon->setGender("male");
    dragon->setAge(20);
    dragon->setName("steven");
     // Capture output
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    // Call the function
    dragon->printCharacterInfo();

    // Restore the original std::cout buffer
    std::cout.rdbuf(oldCoutBuf);

    // Check output
    std::string expectedOutput =
        "Name: steven\n"
        "Age: 20\n"
        "Level: 1\n"
        "Gender: male\n"
        "Species: Dragon\n"
        "XP: 0\n"
        "Attack: 20\n"
        "HP: 100\n"
        "Defense: 10\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
TEST(CharacterTest, PrintInfoDem) {
    Character *demon = new Demon;
    demon->setGender("male");
    demon->setAge(20);
    demon->setName("steven");
     // Capture output
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    // Call the function
    demon->printCharacterInfo();

    // Restore the original std::cout buffer
    std::cout.rdbuf(oldCoutBuf);

    // Check output
    std::string expectedOutput =
        "Name: steven\n"
        "Age: 20\n"
        "Level: 1\n"
        "Gender: male\n"
        "Species: Demon\n"
        "XP: 0\n"
        "Attack: 15\n"
        "HP: 100\n"
        "Defense: 15\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
TEST(CharacterTest, PrintInfoAng) {
    Character *angel = new Angel;
    angel->setGender("male");
    angel->setAge(20);
    angel->setName("steven");
     // Capture output
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    // Call the function
    angel->printCharacterInfo();

    // Restore the original std::cout buffer
    std::cout.rdbuf(oldCoutBuf);

    // Check output
    std::string expectedOutput =
        "Name: steven\n"
        "Age: 20\n"
        "Level: 1\n"
        "Gender: male\n"
        "Species: Angel\n"
        "XP: 0\n"
        "Attack: 10\n"
        "HP: 130\n"
        "Defense: 10\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
TEST(CharacterTest, PrintInfoWiz) {
    Character *wizard = new Wizard;
    wizard->setGender("male");
    wizard->setAge(20);
    wizard->setName("steven");
     // Capture output
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    // Call the function
    wizard->printCharacterInfo();

    // Restore the original std::cout buffer
    std::cout.rdbuf(oldCoutBuf);

    // Check output
    std::string expectedOutput =
        "Name: steven\n"
        "Age: 20\n"
        "Level: 1\n"
        "Gender: male\n"
        "Species: Wizard\n"
        "XP: 0\n"
        "Attack: 15\n"
        "HP: 110\n"
        "Defense: 10\n";

    EXPECT_EQ(output.str(), expectedOutput);
}


TEST(EnemyTests, RandomEnemyInitial){
    Enemy* e1 = new RandomEnemy;
    EXPECT_EQ (e1->getType(),"Random Enemy");
    EXPECT_GE(e1->getDefense(), 6);
    EXPECT_LE(e1->getDefense(), 10);
    EXPECT_GE(e1->getAttack(), 11);
    EXPECT_LE(e1->getAttack(), 15);
    EXPECT_GE(e1->getHP(), 91);
    EXPECT_LE(e1->getHP(), 100);
}

TEST(EnemyTests, MiniBossInitial){
    Enemy* e1 = new MiniBoss;
    EXPECT_EQ (e1->getType(),"Mini Boss");
    EXPECT_GE(e1->getDefense(), 21);
    EXPECT_LE(e1->getDefense(), 30);
    EXPECT_GE(e1->getAttack(), 29);
    EXPECT_LE(e1->getAttack(), 35);
    EXPECT_GE(e1->getHP(), 291);
    EXPECT_LE(e1->getHP(), 300);
}

TEST(EnemyTests, FinalBossInitial){
    Enemy* e1 = new FinalBoss;
    EXPECT_EQ (e1->getType(),"Final Boss");
    EXPECT_EQ(e1->getHP(), 600);
    EXPECT_EQ(e1->getAttack(), 50);
    EXPECT_EQ(e1->getDefense(), 40);
}

TEST(EnemyTests, RandomEnemySetters){
    Enemy* e1 = new RandomEnemy;
    e1->setAttack(20);
    EXPECT_EQ(e1->getAttack(), 20);
    e1->setDefense(17);
    EXPECT_EQ(e1->getDefense(), 17);
    e1->setName("foe");
    EXPECT_EQ(e1->getName(), "foe");
    e1->setHP(70);
    EXPECT_EQ(e1->getHP(), 70);
}

TEST(EnemyTests, MiniBossSetters){
    Enemy* e1 = new MiniBoss;
    e1->setAttack(20);
    EXPECT_EQ(e1->getAttack(), 20);
    e1->setDefense(17);
    EXPECT_EQ(e1->getDefense(), 17);
    e1->setName("foe");
    EXPECT_EQ(e1->getName(), "foe");
    e1->setHP(70);
    EXPECT_EQ(e1->getHP(), 70);
}

TEST(EnemyTests, FinalBossSetters){
    Enemy* e1 = new FinalBoss;
    e1->setAttack(20);
    EXPECT_EQ(e1->getAttack(), 20);
    e1->setDefense(17);
    EXPECT_EQ(e1->getDefense(), 17);
    e1->setName("foe");
    EXPECT_EQ(e1->getName(), "foe");
    e1->setHP(70);
    EXPECT_EQ(e1->getHP(), 70);
}

TEST(EnemyTests, printInfoRandEnemy){
    Enemy *e1 = new RandomEnemy;
    e1->setGender("male");
    e1->setName("nikhil");
    e1->setAttack(15);
    e1->setDefense(15);
    e1->setHP(20);
     // Capture output
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    // Call the function
    e1->printEnemyInfo();

    // Restore the original std::cout buffer
    std::cout.rdbuf(oldCoutBuf);

    // Check output
    std::string expectedOutput =
        "Name: nikhil\n"
        "Type: Random Enemy\n"
        "Level: 1\n"
        "Gender: male\n"
        "Attack: 15\n"
        "HP: 20\n"
        "Defense: 15\n";

    EXPECT_EQ(output.str(), expectedOutput);
}

TEST(EnemyTests, printInfoMiniBoss){
    Enemy *e1 = new MiniBoss;
    e1->setGender("male");
    e1->setName("nikhil");
    e1->setAttack(15);
    e1->setDefense(15);
    e1->setHP(20);
     // Capture output
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    // Call the function
    e1->printEnemyInfo();

    // Restore the original std::cout buffer
    std::cout.rdbuf(oldCoutBuf);

    // Check output
    std::string expectedOutput =
        "Name: nikhil\n"
        "Type: Mini Boss\n"
        "Level: 1\n"
        "Gender: male\n"
        "Attack: 15\n"
        "HP: 20\n"
        "Defense: 15\n";

    EXPECT_EQ(output.str(), expectedOutput);
}

TEST(EnemyTests, printInfoFinalBoss){
    Enemy *e1 = new FinalBoss;
    e1->setGender("male");
    e1->setName("nikhil");
    e1->setAttack(15);
    e1->setDefense(15);
    e1->setHP(20);
     // Capture output
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    // Call the function
    e1->printEnemyInfo();

    // Restore the original std::cout buffer
    std::cout.rdbuf(oldCoutBuf);

    // Check output
    std::string expectedOutput =
        "Name: nikhil\n"
        "Type: Final Boss\n"
        "Level: 100\n"
        "Gender: male\n"
        "Attack: 15\n"
        "HP: 20\n"
        "Defense: 15\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
battleSystem battle;

TEST(BattleSystemTest, PlayerWins) {
   Character* player = new Wizard();
   player->setHP(100);
   player->setAttack(50);


   Enemy* enemy = new RandomEnemy();
   enemy->setHP(50);
   enemy->setAttack(20);


   battle.startBattle(player, enemy, 1);


   EXPECT_GT(player->getHP(), 0); // Player survives
   EXPECT_LE(enemy->getHP(), 0); // Enemy defeated


   delete player;
   delete enemy;
}


TEST(BattleSystemTest, PlayerDefeated) {
   Character* player = new Wizard();
   player->setHP(30);
   player->setAttack(30);


   Enemy* enemy = new RandomEnemy();
   enemy->setHP(100);
   enemy->setAttack(50);


   battle.startBattle(player, enemy, 1);


   EXPECT_LE(player->getHP(), 0); // Player defeated
   EXPECT_GT(enemy->getHP(), 0); // Enemy survives


   delete player;
   delete enemy;
}


TEST(BattleSystemTest, PlayerRunsSuccessfully) {
   Character* player = new Wizard();
   player->setHP(100);
   player->setAttack(30);


   Enemy* enemy = new RandomEnemy();
   enemy->setHP(100);
   enemy->setAttack(30);


   battle.startBattle(player, enemy, 0);


   EXPECT_EQ(player->getHP(), 100); // Player takes no damage
   EXPECT_EQ(enemy->getHP(), 100); // Enemy is unharmed


   delete player;
   delete enemy;
}




TEST(BattleSystemTest, PlayerFailsToRun) {

   Character* player = new Wizard();
   player->setHP(100);
   player->setAttack(30);


   Enemy* enemy = new RandomEnemy();
   enemy->setHP(100);
   enemy->setAttack(20);


   battle.startBattle(player, enemy, 1);


   EXPECT_LT(player->getHP(), 100); // Player takes damage
   EXPECT_EQ(enemy->getHP(), 100); // Enemy is unharmed


   delete player;
   delete enemy;
}

TEST(BattleSystemTest, PlayerUsesItem) {
   Character* player = new Wizard();
   player->setHP(50);
   Item* item = new healthItem("Health Potion");
   player->addItem(item); // Add health item to inventory
   player->useItem(0);

   EXPECT_GT(player->getHP(), 50); // Player uses the item and regains HP
   EXPECT_EQ(player->getInventorySize(), 0); // Inventory is empty after item use

   delete player;
   delete item;
}

// test input 3 -2 3 -1 2
TEST(BattleSystemTest, InvalidInventoryChoiceOrCancel) {
   Character* player = new Wizard();
   player->setHP(100);
   player->addItem(new healthItem("Health Potion"));


   Enemy* enemy = new RandomEnemy();
   enemy->setHP(100);
   enemy->setAttack(20);


   battle.startBattle(player, enemy, 0);


   EXPECT_EQ(player->getHP(), 100); // No HP change for invalid item usage
   EXPECT_EQ(player->getInventorySize(), 1); // Item still present in inventory


   delete player;
   delete enemy;
}


// Test case: Enemy defeated by a player with critical damage
TEST(BattleSystemTest, PlayerCriticalDamage) {
   Character* player = new Wizard();
   player->setHP(100);
   player->setAttack(150); // High attack power


   Enemy* enemy = new RandomEnemy();
   enemy->setHP(100);
   enemy->setAttack(20);


   battle.startBattle(player, enemy, 1);


   EXPECT_GT(player->getHP(), 0); // Player survives
   EXPECT_LE(enemy->getHP(), 0); // Enemy is defeated in one hit


   delete player;
   delete enemy;
}
//Test case: gain xp and level up
TEST(BattleSystemTest, levelUp){
    Character* player = new Wizard();
   player->setHP(100);
   player->setAttack(50);


   Enemy* enemy = new RandomEnemy();
   enemy->setHP(50);
   enemy->setAttack(20);


   battle.startBattle(player, enemy, 1);
   battle.startBattle(player, enemy, 1);


   EXPECT_EQ(2, player->getLevel());


   delete player;
   delete enemy;

}
TEST(BattleSystemTest, CorrectXp){
    Character* player = new Wizard();
   player->setHP(100);
   player->setAttack(50);


   Enemy* enemy = new RandomEnemy();
   enemy->setHP(50);
   enemy->setAttack(20);


   battle.startBattle(player, enemy, 1);
   battle.startBattle(player, enemy, 1);
   battle.startBattle(player, enemy, 1);


   EXPECT_EQ(2, player->getLevel());
   EXPECT_EQ(50, player->getXP());


   delete player;
   delete enemy;

}
TEST(BattleSystemTest, LevelUpStats){
    Character* player = new Wizard();
   player->setHP(100);
   player->setAttack(50);


   Enemy* enemy = new RandomEnemy();
   enemy->setHP(50);
   enemy->setAttack(20);


   battle.startBattle(player, enemy, 1);
   battle.startBattle(player, enemy, 1);
   battle.startBattle(player, enemy, 1);


   EXPECT_EQ(120, player->getHP());
   EXPECT_EQ(70, player->getAttack());


   delete player;
   delete enemy;

}

//Test case: gain xp and level up
TEST(BattleSystemTest, levelUp){
    Character* player = new Wizard();
   player->setHP(100);
   player->setAttack(50);
   Enemy* enemy = new RandomEnemy();
   enemy->setHP(50);
   enemy->setAttack(20);
   battle.startBattle(player, enemy, 1);
   battle.startBattle(player, enemy, 1);
   EXPECT_EQ(2, player->getLevel());
   delete player;
   delete enemy;
}
TEST(BattleSystemTest, CorrectXp){
    Character* player = new Wizard();
   player->setHP(100);
   player->setAttack(50);
   Enemy* enemy = new RandomEnemy();
   enemy->setHP(50);
   enemy->setAttack(20);
   battle.startBattle(player, enemy, 1);
   battle.startBattle(player, enemy, 1);
   battle.startBattle(player, enemy, 1);
   EXPECT_EQ(2, player->getLevel());
   EXPECT_EQ(50, player->getXP());
   delete player;
   delete enemy;
}
TEST(BattleSystemTest, LevelUpStats){
    Character* player = new Wizard();
   player->setHP(100);
   player->setAttack(50);
   Enemy* enemy = new RandomEnemy();
   enemy->setHP(50);
   enemy->setAttack(20);
   battle.startBattle(player, enemy, 1);
   battle.startBattle(player, enemy, 1);
   battle.startBattle(player, enemy, 1);
   EXPECT_EQ(120, player->getHP());
   EXPECT_EQ(70, player->getAttack());
   delete player;
   delete enemy;
}





