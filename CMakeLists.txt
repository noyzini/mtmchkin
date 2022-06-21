cmake_minimum_required(VERSION 3.16)
project(mtmchkin)

set(CMAKE_CXX_STANDARD 11)

add_executable(mtmchkin
        tool/main.cpp
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
        Cards/BattleCard.cpp
        Cards/BattleCard.h
        Cards/Dragon.cpp
        Cards/Dragon.h
        Cards/Goblin.cpp
        Cards/Goblin.h
        Cards/Vampire.cpp
        Cards/Vampire.h
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Pitfall.cpp
        Cards/Pitfall.h
        Cards/Barfight.cpp
        Cards/Barfight.h
        Cards/Fairy.cpp
        Cards/Fairy.h
        Cards/Merchant.cpp
        Cards/Merchant.h
        Cards/Gang.cpp
        Cards/Gang.h
        Leaderboard.cpp
        Leaderboard.h)
