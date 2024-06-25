cmake_minimum_required(VERSION 3.28)
project(Pong)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(Pong
    src/Paddle.h
    src/Paddle.cpp
    src/Ball.cpp
    src/Ball.h
    src/IUpdatable.h
    src/ICollideable.h
    src/Wall.cpp
    src/Wall.h
    src/Game.cpp
    src/Game.h
    src/IDrawable.h
    src/Score.cpp
    src/Score.h
    src/IAnimatable.h
)

# If your SFML installation is located in a non-standard directory, set the SFML_DIR variable here. E.g.
# set(SFML_DIR "/usr/lib/x86_64-linux-gnu/cmake/SFML/")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(Pong sfml-graphics sfml-window sfml-system)
target_include_directories(Pong PRIVATE ${SFML_INCLUDE_DIR})
