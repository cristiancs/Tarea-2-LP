cmake_minimum_required(VERSION 3.6)
project(Tarea_2_LP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES libraries/pcg-c-basic-0.9/pcg_basic.c lista.c CartaCurso.c Sansano.c  main.c)
add_executable(Tarea_2_LP ${SOURCE_FILES})