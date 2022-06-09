cmake_minimum_required(VERSION 3.16)
project(mtmchkin)

set(CMAKE_CXX_STANDARD 11)

add_executable(mtmchkin
        main.cpp
        Mtmchkin.h
        Mtmchkin.cpp
        Players/Player.h
        Players/Player.cpp
        Players/Rogue.cpp
        Players/Rogue.h
        Players/Wizard.cpp
        Players/Wizard.h
        Players/Fighter.cpp
        Players/Fighter.h
        utilities.h
        utilities.cpp
        HealthPoints.h
        HealthPoints.cpp
        Queue.h
        Exception.h
        Cards/Card.cpp
        Cards/Card.h
        Cards/BattleCards/BattleCards.cpp
        Cards/BattleCards/BattleCards.h
        Cards/BattleCards/Dragon.cpp
        Cards/BattleCards/Dragon.h
        Cards/BattleCards/Goblin.cpp
        Cards/BattleCards/Goblin.h
        Cards/BattleCards/Vampire.cpp
        Cards/BattleCards/Vampire.h
        Cards/Treasure.cpp
        Cards/Treasure.h)
