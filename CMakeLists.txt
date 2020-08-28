cmake_minimum_required(VERSION 3.17)
project(iuaProject)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML2.5 COMPONENTS system window graphics)

add_executable(iuaProject main.cpp classes/Engine.cpp classes/Engine.h classes/Jake.cpp classes/Jake.h classes/Maggie.cpp classes/Maggie.h classes/EnemyMob.cpp classes/EnemyMob.h classes/Input.cpp classes/Update.cpp classes/Draw.cpp)
target_link_libraries(iuaProject sfml-system sfml-window sfml-graphics)