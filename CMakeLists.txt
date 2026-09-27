cmake_minimum_required(VERSION 3.16)
project(SkeletonQuest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(skeleton_quest
    src/main.cpp
    src/Player.cpp
    src/CharacterCreate.cpp
    src/Monster.cpp
    src/Store.cpp
    src/Area.cpp
    src/Art.cpp
    src/Input.cpp
    src/SaveSystem.cpp
)

if(MSVC)
    target_compile_options(skeleton_quest PRIVATE /W4 /WX)
else()
    target_compile_options(skeleton_quest PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()