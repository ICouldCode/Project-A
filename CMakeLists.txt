cmake_minimum_required(VERSION 3.12)
project(RaylibMacProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Force CMake to look into Homebrew paths on Mac
if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew" "/usr/local")
endif()

find_package(raylib REQUIRED)

add_executable(MyRaylibGame main.cpp)

target_link_libraries(MyRaylibGame PRIVATE raylib)
