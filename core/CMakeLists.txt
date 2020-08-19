cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(darabonba_core LANGUAGES CXX)

add_library(darabonba_core 
    STATIC 
    core.hpp
    core.cpp)
