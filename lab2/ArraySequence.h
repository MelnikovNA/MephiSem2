//
// Created by Stif on 21.04.2023.
//

#ifndef LAB2_ARRAYSEQUENCE_H
#define LAB2_ARRAYSEQUENCE_H
#include <iostream>

using namespace std;
namespace da {
    template<class T>
    class DynamicArray {
    private:
        T *data;
        unsigned int size;
        unsigned int capt;

        void extend();

    public:
        DynamicArray();

        DynamicArray(int max_size);

        DynamicArray(T *items, int count);

        ~DynamicArray();

        DynamicArray(DynamicArray<T> &dynamicArrayconst);

        int GetSize();

        void Set(int index, T value);

        void Resize(int newSize);

        void print();

        void push(T value);

        T &operator[](int index) { return data[index]; };
    };
}
template<class T>
da::DynamicArray<T>::DynamicArray() {
    data = NULL;
    size = 0;
    capt = 0;
};

template<class T>
void da::DynamicArray<T>::extend() {
    T*newData = new T [capt+10];
    for(int i =0; i<capt; i++){
        newData[i]=data[i];
    }
    delete [] data;
    data  = newData;
    capt+=10;
}

template<class T>
da::DynamicArray<T>::DynamicArray(int max_size) {
    capt = max_size;
    this->size=0;
    data = new T[capt];
}

template<class T>
da::DynamicArray<T>::DynamicArray(T *items, int count) {
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
da::DynamicArray<T>::~DynamicArray() {
    delete [] data;
    size = 0;
    capt = 0;
}

template<class T>
da::DynamicArray<T>::DynamicArray(DynamicArray<T> &dynamicArrayconst){
    this->data = new T(dynamicArrayconst.capt);
    for(int i = 0; i<dynamicArrayconst.size;i++){
        data[i]=dynamicArrayconst.data[i];
    }
    this->capt=dynamicArrayconst.capt;
    this->size=dynamicArrayconst.size;
}

template <class T>
int da::DynamicArray<T>::GetSize() {return size;}

template<class T>
void da::DynamicArray<T>::Resize(int newSize) {
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
void da::DynamicArray<T>::Set(int index, T value) {
    if(index>=size){
        throw "IndexOutOfRange";
    };
    data[index]=value;
};
template<class T>
void da::DynamicArray<T>::print() {
    for(int i =0; i<size;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void da::DynamicArray<T>::push(T value) {
    if(size==capt){
        extend();
    }
    data[size] = value;
    size++;

}
#endif //LAB2_ARRAYSEQUENCE_H
