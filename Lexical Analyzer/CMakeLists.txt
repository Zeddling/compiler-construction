cmake_minimum_required(VERSION 3.15)
project(lexical_analyzer)

set(CMAKE_CXX_STANDARD 17)
add_executable( lexical main.cpp "classes/lexical.cpp" "classes/lexical.h" )