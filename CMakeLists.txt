cmake_minimum_required(VERSION 3.8)
project(BFS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Vertice.cpp Vertice.h Grafo.cpp Grafo.h)
add_executable(BFS ${SOURCE_FILES})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")