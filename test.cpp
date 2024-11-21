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
    EXPECT_EQ(player1->getAttack(), 20);
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
    demon->initialize();
    EXPECT_EQ (demon->getSpecies(),"Demon");
    EXPECT_EQ (demon->getAttack(),15);
    EXPECT_EQ (demon->getDefense(),15);
}
TEST(CharacterTest, angelInitial) {
    Character *angel = new Angel;
    angel->initialize();
    EXPECT_EQ (angel->getSpecies(),"Angel");
    EXPECT_EQ (angel->getHP(),130);
 
}
TEST(CharacterTest, dragonInitial) {
    Character *dragon = new Dragon;
    dragon->initialize();
    EXPECT_EQ (dragon->getSpecies(),"Dragon");
    EXPECT_EQ (dragon->getAttack(),20);
 
}
TEST(CharacterTest, wizardInitial) {
    Character *wizard = new Wizard;
    wizard->initialize();
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

    EXPECT_EQ(player->getHP(), 110);
}

TEST(InventoryTest, removeItemAfterUse) {
    Character* player = new Angel;
    Inventory inventory;
    Item* item = new healthItem("health potion");
    inventory.addItem(item);
    inventory.useItem(player, 0);

    EXPECT_EQ(inventory.getSize(), 0);
}

// ==================================================

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