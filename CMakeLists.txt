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
        Game.cpp Game.hpp
        Nc.cpp Nc.hpp
        Conroller.cpp Controller.hpp
        Bonus.cpp Bonus.hpp
        Bonus1.cpp Bonus1.hpp
        Bonus2.cpp Bonus2.hpp
        Bonus3.cpp Bonus3.hpp
        Bonus4.cpp Bonus4.hpp
        Bonus5.cpp Bonus5.hpp
        Bonus6.cpp Bonus6.hpp
        roundfTanks.cpp Menu.cpp Menu.hpp Survival.cpp Survival.hpp)
