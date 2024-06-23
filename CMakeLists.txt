cmake_minimum_required(VERSION 3.28)
project(Pong)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(Pong
        Paddle.h
        Paddle.cpp
        Ball.cpp
        Ball.h
        IMovable.h
        ICollideable.h
        Wall.cpp
        Wall.h
        Game.cpp
        Game.h
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(Pong sfml-graphics sfml-window sfml-system)
target_include_directories(Pong PRIVATE ${SFML_INCLUDE_DIR})
