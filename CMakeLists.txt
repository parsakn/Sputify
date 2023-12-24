cmake_minimum_required(VERSION 3.26)
project(sputify)

set(CMAKE_CXX_STANDARD 20)

add_executable(sputify main.cpp
        SputifyCore.cpp
        SputifyCore.h
        Account.cpp
        Account.h
        Manual.h
        Commandler.cpp
        Commandler.h
        IdGenerator.cpp
        IdGenerator.h
        Song.cpp
        Song.h
        Duration.cpp
        Duration.h)
