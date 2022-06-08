cmake_minimum_required(VERSION 3.16)
project(mtmchkin)

set(CMAKE_CXX_STANDARD 11)

add_executable(mtmchkin
        main.cpp
        Card.h
        Mtmchkin.h
        Players/Player.h Players/Player.cpp utilities.h utilities.cpp Card.cpp Mtmchkin.cpp
        HealthPoints.h HealthPoints.cpp Queue.h Exception.h Players/Rogue.cpp Players/Rogue.h Players/Wizard.cpp Players/Wizard.h Players/Fighter.cpp Players/Fighter.h)
