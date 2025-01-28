cmake_minimum_required(VERSION 3.30)
project(unit_test)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        main.cpp
        MyMathLib.h
        test.cpp
)


add_executable(unit_test main.cpp)