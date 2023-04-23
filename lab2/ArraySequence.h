//
// Created by Stif on 21.04.2023.
//

#ifndef LAB2_ARRAYSEQUENCE_H
#define LAB2_ARRAYSEQUENCE_H
#include <iostream>

using namespace std;

template<class T>class DynamicArray{
private:
    T *data;
    unsigned int size;
    unsigned int capt;
public:
    DynamicArray(); //конструктор по умолчанию done
    DynamicArray(int max_size);//done
    DynamicArray(T*items, int count);//done
    ~DynamicArray();//done
    DynamicArray(DynamicArray<T> &dynamicArrayconst);//done
    int GetSize();//done
    void Set(int index, T value);//done
    void Resize(int newSize);//done
    void print();//done
};

template<class T>
DynamicArray<T>::DynamicArray() {
    data = NULL;
    size = 0;
    capt = 0;
};

template<class T>
DynamicArray<T>::DynamicArray(int size) {
    capt = 10;
    this->size = size;
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
}

#endif //LAB2_ARRAYSEQUENCE_H
