cmake_minimum_required(VERSION 3.25)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp DynamicArray.h Sequence.h IndexOutOfRangeException.h LinkedList.h ArraySequence.h LinkedListSequence.h)
add_executable(Seqtest SeqTest.cpp DynamicArray.h Sequence.h IndexOutOfRangeException.h LinkedList.h ArraySequence.h LinkedListSequence.h)
add_executable(LinkedListTest  linkedListTests.cpp DynamicArray.h Sequence.h IndexOutOfRangeException.h LinkedList.h ArraySequence.h LinkedListSequence.h)
add_executable(DynamicArrTest dynamicArrTests.cpp DynamicArray.h Sequence.h IndexOutOfRangeException.h LinkedList.h ArraySequence.h LinkedListSequence.h)