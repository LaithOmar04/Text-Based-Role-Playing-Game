cmake_minimum_required(VERSION 3.14)
project(MyRPGGame)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add Google Test directory 
add_subdirectory(googletest)

# Main program executable
add_executable(MainExecutable 
main.cpp )

# Test executable
add_executable(UnitTests 
test.cpp )

# Link Google Test libraries to the UnitTests executable
target_link_libraries(UnitTests gtest gtest_main)