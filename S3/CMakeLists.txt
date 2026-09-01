cmake_minimum_required(VERSION 4.0)
project(S3)

set(CMAKE_CXX_STANDARD 20)

add_executable(S3 main.cpp
        doubly_linked_list.cpp
        round_robin.cpp
        polinomios.cpp
        josephus.cpp)
