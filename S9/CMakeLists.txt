cmake_minimum_required(VERSION 4.0)
project(S9)

set(CMAKE_CXX_STANDARD 20)

add_executable(S9 AVL.cpp
        es_un_avl.cpp
        alturas_en_un_avl.cpp
)
