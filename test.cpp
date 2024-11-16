#include "gtest/gtest.h"
#include "healthItem.h"
#include "attackItem.h"
#include "defenseItem.h"
#include "character.h"

TEST(ItemTests, healthItemConstructor){
    healthItem item1("item1");
    EXPECT_EQ(item1.getName(), "item1");
    EXPECT_EQ(item1.getAbility(), "health");
    EXPECT_EQ(item1.getStrength(), 10);
}

TEST(ItemTests, healthItemAbility){
    Character* player1 = new Character;
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
    Character* player1 = new Character;
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
    Character* player1 = new Character;
    defenseItem item1("item1");
    item1.useAbility(player1);
    EXPECT_EQ(player1->getDefense(), 20);
=======

TEST(CharacterTest, demonInitial) {
    Character *demon = new Character("steven",19,"male","Demon");
    EXPECT_EQ (demon->getSpecies(),"Demon");
    EXPECT_EQ (demon->getAttack(),15);
    EXPECT_EQ (demon->getDefense(),15);
}
TEST(CharacterTest, angelInitial) {
    Character *angel = new Character("steven",19,"male","Angel");
    EXPECT_EQ (angel->getSpecies(),"Angel");
    EXPECT_EQ (angel->getHP(),130);
 
}
TEST(CharacterTest, dragonInitial) {
    Character *dragon = new Character("steven",19,"male","Dragon");
    EXPECT_EQ (dragon->getSpecies(),"Dragon");
    EXPECT_EQ (dragon->getAttack(),20);
 
}
TEST(CharacterTest, wizardInitial) {
    Character *wizard = new Character("steven",19,"male","Wizard");
    EXPECT_EQ (wizard->getSpecies(),"Wizard");
    EXPECT_EQ (wizard->getAttack(),15);
     EXPECT_EQ (wizard->getHP(),110);
 
}
TEST(CharacterTest, name) {
    Character *dragon = new Character("steven",19,"male","Dragon");
    EXPECT_EQ (dragon->getName(),"steven");
 
}
TEST(CharacterTest, age) {
    Character *dragon = new Character("steven",19,"male","Dragon");
    EXPECT_EQ (dragon->getAge(),19);
 
}
TEST(CharacterTest, gender) {
    Character *dragon = new Character("steven",19,"male","Dragon");
    EXPECT_EQ (dragon->getGender(),"male");
 
}