cmake_minimum_required(VERSION 3.9)
project(ttt)

set(CMAKE_CXX_STANDARD 11)

add_executable(ttt main.cpp
        BestTanks.h
        Bullet.cpp Bullet.hpp
        Tank.cpp Tank.hpp
        Player.cpp Player.hpp
        Enemy.cpp Enemy.hpp
        Eagle.cpp Eagle.hpp
        Texture.cpp Texture.hpp
        XYWay.cpp XYWay.hpp
        Battle.cpp Battle.hpp
        Nc.cpp Nc.hpp
        Conroller.cpp Controller.hpp
        roundfTanks.cpp)
