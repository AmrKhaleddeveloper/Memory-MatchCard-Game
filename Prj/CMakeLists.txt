cmake_minimum_required(VERSION 3.27)
project(Prj)

set(CMAKE_CXX_STANDARD 17)

add_executable(Prj main.cpp
        Card.h
        StandardCard.h
        BonusCard.h
        PenaltyCard.h
        Deck.h
        Player.h
        Game.h
        Card.cpp
        Deck.cpp
        Game.cpp
        PenaltyCard.cpp
        Player.cpp
        StandardCard.cpp
        BonusCard.cpp
)
