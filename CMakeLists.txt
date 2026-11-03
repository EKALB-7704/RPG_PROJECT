cmake_minimum_required(VERSION 3.16)
project(SkeletonQuest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # lets editors see the real compiler flags

# Shared warning flags, so every target agrees and nothing is duplicated.
add_library(project_warnings INTERFACE)
if(MSVC)
    target_compile_options(project_warnings INTERFACE /W4 /WX)
else()
    target_compile_options(project_warnings INTERFACE
        -Wall -Wextra -Wpedantic -Wshadow -Werror)
endif()

# All game logic lives here so that both the executable and (from the next
# commit onward) the test binary can link against it.
add_library(game_core STATIC
    src/Player.cpp
    src/CharacterCreate.cpp
    src/Monster.cpp
    src/Battle.cpp
    src/Store.cpp
    src/Area.cpp
    src/Art.cpp
    src/Input.cpp
    src/SaveSystem.cpp
    src/Rng.cpp
)
target_include_directories(game_core PUBLIC src)
target_link_libraries(game_core PRIVATE project_warnings)

# Thin wrapper: menu wiring only.
add_executable(skeleton_quest src/main.cpp)
target_link_libraries(skeleton_quest PRIVATE game_core project_warnings)

enable_testing()
add_executable(tests tests/test_player.cpp tests/test_rng.cpp)
target_link_libraries(tests PRIVATE game_core project_warnings)
target_include_directories(tests SYSTEM PRIVATE third_party)
add_test(NAME unit COMMAND tests)
