//
// Created by Stif on 21.04.2023.
//

/*#include "ArraySequence.h"
#include <iostream>
using namespace std;

template<class T>
DynamicArray<T>::DynamicArray() {
    data = NULL;
    size = 0;
    capt = 0;
};

template<class T>
DynamicArray<T>::DynamicArray(int max_size) {
    capt = max_size;
    size = 0;
    data = new T[capt];
}

template<class T>
DynamicArray<T>::DynamicArray(T *items, int count) {
    while(count>capt){
        capt+=10;
    }
    data = new T[capt];
    for(int i = 0; i<count;i++){
        data[i]=items[i];
    }
    size = count;
}

template<class T>
DynamicArray<T>::~DynamicArray() {
    delete [] data;
    size = 0;
    capt = 0;
}

template<class T>
DynamicArray<T>::DynamicArray(DynamicArray<T> &dynamicArrayconst){
    this->data=dynamicArrayconst.data;
    this->capt=dynamicArrayconst.capt;
    this->size=dynamicArrayconst.size;
}

template <class T>
int DynamicArray<T>::GetSize() {return size;}

template<class T>
void DynamicArray<T>::Resize(int newSize) {
    while(newSize>=capt)capt+=10;
    T *newData = new T[capt];
    int i=0;
    while(i<newSize and i<size){
        newData[i]=data[i];
        i++;
    }
    delete [] data;
    size=newSize;
    data = newData;
}

template<class T>
void DynamicArray<T>::Set(int index, T value) {
    if(index>=size){
        throw "IndexOutOfRange";
    };
    data[index]=value;
};
template<class T>
void DynamicArray<T>::print() {
    for(int i =0; i<size;i++){
        cout<<data[i]<<" "<<endl;
    }
}*/