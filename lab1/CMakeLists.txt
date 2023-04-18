cmake_minimum_required(VERSION 3.23)
project(lab1 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab1 main.c RingInfo.h RingInfo.c Vector.h Vector.c ints.h ints.c double.h double.c menu.h menu.c)
