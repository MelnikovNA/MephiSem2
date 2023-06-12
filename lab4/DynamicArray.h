//
// Created by Stif on 10.06.2023.
//
#include <string>
#include <iostream>
#include "cstring"
#include "IndexOutOfRangeException.h"


template <class T>
class DynamicArray {
private:
    T *array;
    int length;
    size_t sizeOfElement = sizeof(T);
public:
    DynamicArray(T a){
        array = new T[1];
        array[0] = a;
        length = 1;
    }

    DynamicArray(){
        length = 0;
        array = nullptr;
    }

    DynamicArray(T* items, int count) {
        length = 0;
        if(count>0){
            array = new T[count];
            for(; length<count; length++){
                array[length] = items[length];
            }
        }
    }

   // DynamicArray(int size) {
   //     length = size;
   //     array = new T[size];
   //     for(int i = 0; i<size; i++) array[i] = 0;
   // }

    DynamicArray(const DynamicArray<T> &dynamicArray ) {
        length = 0;
        array = new T[dynamicArray.length];
        for(; length<dynamicArray.length; length++){
            array[length] = dynamicArray.array[length];
        }
    }

    T Get(int index) {
        if(index>length||index<0) throw IndexOutOfRange();
        return array[index];
    }

    void Set(int index, T value) {
        if(index>length||index<0) throw IndexOutOfRange();
        array[index] = value;
    }

    void Resize(int newSize){
        T *newArr = new T[newSize];
        if(array == nullptr){
            for (int i = 0; i < newSize; ++i) {
                newArr[i] = 0;
            }
        }else {
            for (int i = 0; i < newSize; ++i) {
                newArr[i] = array[i % length];
            }
        }
        length = newSize;
        delete[] array;
        array = newArr;
    }

    int GetLength() {
        return length;
    }

    friend std::ostream& operator<<(std::ostream &out, DynamicArray dynamicArray){
        out<<""<<std::endl;
        for (int i = 0; i < dynamicArray.length; ++i) {
            out<<dynamicArray.Get(i);
        }
        out<<""<<std::endl;
        return out;
    }
};




