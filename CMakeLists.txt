cmake_minimum_required(VERSION 3.17)
project(iuaProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(iuaProject main.cpp classes/Engine.cpp classes/Engine.h classes/Jake.cpp classes/Jake.h classes/Maggie.cpp classes/Maggie.h classes/EnemyMob.cpp classes/EnemyMob.h)