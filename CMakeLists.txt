cmake_minimum_required(VERSION 3.14)
project(MyRPGGame)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add Google Test directory 
add_subdirectory(googletest)

# Main program executable
add_executable(MainExecutable 
main.cpp
character.cpp
item.cpp
attackItem.cpp
defenseItem.cpp
healthItem.cpp
inventory.cpp )

# Test executable
ADD_EXECUTABLE(UnitTests 
test.cpp
character.cpp
item.cpp
attackItem.cpp
defenseItem.cpp
healthItem.cpp
inventory.cpp )

# Link Google Test libraries to the UnitTests executable
target_link_libraries(UnitTests gtest gtest_main)