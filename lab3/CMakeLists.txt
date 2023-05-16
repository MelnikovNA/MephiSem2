cmake_minimum_required(VERSION 3.25)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 main.cpp ArraySequence.h DynamicArray.h IndexOutOfRangeException.h LinkedList.h LinkedListSequence.h Sequence.h Vector.h Vectest.cpp vecfunc.cpp vecfunc.h SupInstruments.cpp SupInstruments.h)
add_executable(vectest Vectest.cpp ArraySequence.h DynamicArray.h IndexOutOfRangeException.h LinkedList.h LinkedListSequence.h Sequence.h Vector.h)
