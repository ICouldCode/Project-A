cmake_minimum_required(VERSION 3.12)
project(RaylibMacProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Force CMake to look into Homebrew paths on Mac
if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew" "/usr/local")
endif()

find_package(raylib REQUIRED)

add_executable(MyRaylibGame
    source/main.cpp
    source/collider_component.cpp
    source/physics_system.cpp
    source/player_move.cpp
)

target_include_directories(MyRaylibGame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/header
)

target_link_libraries(MyRaylibGame PRIVATE raylib)

add_custom_command(TARGET MyRaylibGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/images.png
            $<TARGET_FILE_DIR:MyRaylibGame>/images.png
)
