cmake_minimum_required(VERSION 3.17)
project(iuaProject)

set(CMAKE_CXX_STANDARD 14)

set(SFML_VERSION "2.5.1")
find_package(SFML ${SFML_VERSION} COMPONENTS system window graphics QUIET)

# If not present. Download and compile SFML
if (NOT SFML_FOUND)
    include(FetchContent)
    set(FETCHCONTENT_QUIET NO)

    FetchContent_Declare(
            sfml URL https://github.com/SFML/SFML/releases/download/${SFML_VERSION}/SFML-${SFML_VERSION}-sources.zip
    )

    FetchContent_GetProperties(sfml)
    if(NOT sfml_POPULATED)
        FetchContent_Populate(sfml)
        add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
    endif()
endif()

add_executable(iuaProject
        main.cpp
        classes/Engine.cpp
        classes/Player.cpp
        classes/Input.cpp
        classes/Update.cpp
        classes/Draw.cpp
        classes/Habilidad.cpp
        classes/Boss.cpp
        classes/CheckForCollisions.cpp
        classes/Enemy.cpp
        classes/Level.cpp)

target_link_libraries(iuaProject sfml-system sfml-window sfml-graphics)

# Copy assets to Build directory
add_custom_command(
        TARGET iuaProject POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets)