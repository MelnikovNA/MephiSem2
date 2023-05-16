//
// Created by Stif on 21.04.2023.
//

#ifndef LAB2_DYNAMICARRAY_H
#define LAB2_DYNAMICARRAY_H

#include <iostream>
#include "IndexOutOfRangeException.h"
#define SIZE 5
using namespace std;

template <class T>
class DynamicArray
{
    int size = 0;
    int capacity = 0;
    T* data;
public:

    DynamicArray(T* items, int count) : size(count){
        capacity = (count % SIZE == 0) ? SIZE * (count / SIZE) : SIZE * (count / SIZE + 1);
        this->data = new T[capacity];
        for (int i = 0; i < count; i++)
        {
            this->data[i] = items[i];
        }
    };

    DynamicArray(int size) : capacity(size){
        this->data = new T[size];
    };

    DynamicArray(){
        this->data = NULL;
        this->size = 0;
    };

    DynamicArray(DynamicArray<T>& dynamicArray) : size(dynamicArray.size){
        capacity = (size % SIZE == 0) ? SIZE * (size / SIZE) : SIZE * (size / SIZE + 1);
        this->data = new T[capacity];
        for (int i = 0; i < this->size; i++)
        {
            this->data[i] = dynamicArray.get(i);
        }
    };

    ~DynamicArray(){
        if(data != NULL)
            delete [] data;
    };

    void Set(int index, T value){
            if (size == 0) throw IndexOutOfRangeException(Empty);
            if (index < 0 || index > size) throw IndexOutOfRangeException(Invalid);
            data[index] = value;
    }

    void Resize(int newSize){
        capacity = (newSize % SIZE == 0) ? SIZE * (newSize / SIZE) : SIZE * (newSize / SIZE + 1);
        T* newData = new T[capacity];
        for (int i = 0; i < (newSize > size ? size : newSize); i++)
        {
            newData[i] = data[i];
        }
        delete data;
        data = newData;
        size = newSize;
    }

    DynamicArray<T>* Concat(DynamicArray<T>& lst){
        T* newData = new T[this->size + lst.getSize() + 1];
        for (int i = 0; i < this->size; i++)
        {
            newData[i] = this->data[i];
        }
        for (int i = 0; i < lst.getSize(); i++)
        {
            newData[i + this->size] = lst.get(i);
        }
        DynamicArray<T>* nw = new DynamicArray(newData, this->size + lst.getSize() + 1);
        delete[] newData;
        return nw;
    };

    int GetSize(){return this->size;};

    T Get(int index){
            if (size == 0) throw IndexOutOfRangeException(Empty);
            if (index >= size || index < 0) throw IndexOutOfRangeException(Invalid);
            return this->data[index];
    };

    DynamicArray<T>* GetSubAr(int startIndex, int fin){
            if (startIndex < 0 || startIndex >= size || fin >= size || fin < 0 || startIndex > fin) throw IndexOutOfRangeException(Invalid);
            T* ar = new T[fin - startIndex + 1];
            for (int i = startIndex; i <= fin; i++){
                ar[i - startIndex] = data[i];
            }
            DynamicArray<T>* retval = new DynamicArray<T>(ar, fin - startIndex + 1);
            delete[] ar;
            return retval;
    }

    T operator[](const int i){
            if (size == 0) throw IndexOutOfRangeException(Empty);
            if (i < 0 || i >= size) throw IndexOutOfRangeException(Invalid);
            return this->data[i];
    };

    friend ostream& operator<<(ostream &out, DynamicArray dynamicData){
        out<<""<<endl;
        for(int i =0; i< dynamicData.size;i++){
            out<<dynamicData.Get(i);
        }
        out<<""<<endl;
        return out;
    }

};

#endif //LAB2_DYNAMICARRAY_H
