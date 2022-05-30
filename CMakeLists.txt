cmake_minimum_required(VERSION 3.16)
project(mtmchkin)

set(CMAKE_CXX_STANDARD 11)

add_executable(mtmchkin main.cpp Card.h Mtmchkin.h Player.cpp Player.h utilities.h utilities.cpp Card.cpp Mtmchkin.cpp
        HealthPoints.h HealthPoints.cpp Queue.cpp Queue.h Node.h)
        #TestMain.cpp QueueExampleTests.cpp TestUtils.h HealthPointsExampleTest.cpp)
