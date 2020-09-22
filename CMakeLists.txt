cmake_minimum_required(VERSION 3.17)
project(iuaProject)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML2.5 COMPONENTS system window graphics)

add_executable(iuaProject
        main.cpp
        classes/Engine.cpp
        classes/Engine.h
        classes/Player.cpp
        classes/Player.h
        classes/Maggie.cpp
        classes/Maggie.h
        classes/Input.cpp
        classes/Update.cpp
        classes/Draw.cpp
        classes/Jefe.h
        classes/Habilidad.cpp
        classes/Habilidad.h
        classes/Jefe.cpp
        classes/UpdateCollision.cpp
        classes/Enemy.cpp
        classes/Enemy.h
        classes/Level.cpp classes/Level.h classes/Goblin.cpp classes/Goblin.h classes/Bullet.cpp classes/Bullet.h)
target_link_libraries(iuaProject sfml-system sfml-window sfml-graphics)