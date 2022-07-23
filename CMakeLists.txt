cmake_minimum_required(VERSION 3.21)
project(FoodTracker)

set(CMAKE_CXX_STANDARD 14)

add_executable(FoodTracker main.cpp UserPrompts.cpp UserPrompts.h FoodTracker.cpp FoodTracker.h)
