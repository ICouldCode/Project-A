cmake_minimum_required(VERSION 3.12)
project(RaylibMacProject CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find raylib installed via Homebrew
find_package(raylib REQUIRED)

# Define your executable and list your source files (add more if needed)
add_executable(MyRaylibGame main.cpp)

# Link raylib and required Mac system frameworks
target_link_libraries(MyRaylibGame PRIVATE raylib)