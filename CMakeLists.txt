cmake_minimum_required(VERSION 3.14)
project(MyRPGGame)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add Google Test directory 
add_subdirectory(googletest)

# Main program executable
add_executable(MainExecutable 
main.cpp
src/character.cpp
src/wizard.cpp
src/demon.cpp
src/dragon.cpp
src/angel.cpp
src/item.cpp
src/attackItem.cpp
src/defenseItem.cpp
src/healthItem.cpp
src/inventory.cpp
src/rewardSystem.cpp
src/enemy.cpp
src/finalBoss.cpp
src/miniBoss.cpp
src/randomEnemy.cpp )

# Test executable
ADD_EXECUTABLE(UnitTests 
test.cpp
src/character.cpp
src/wizard.cpp
src/demon.cpp
src/dragon.cpp
src/angel.cpp
src/item.cpp
src/attackItem.cpp
src/defenseItem.cpp
src/healthItem.cpp
src/inventory.cpp
src/rewardSystem.cpp 
src/enemy.cpp
src/finalBoss.cpp
src/miniBoss.cpp
src/randomEnemy.cpp )

# Link Google Test libraries to the UnitTests executable
target_link_libraries(UnitTests gtest gtest_main)