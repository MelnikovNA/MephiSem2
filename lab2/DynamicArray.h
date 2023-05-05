//
// Created by Stif on 21.04.2023.
//

#ifndef LAB2_DYNAMICARRAY_H
#define LAB2_DYNAMICARRAY_H

#include <iostream>
#include "IndexOutOfRangeException.h"

using namespace std;

    template<class T>
    class DynamicArray {
    private:
        static const int DEFAULT_CAPACITY = 10;
        T *data = nullptr;
        size_t sizeofElement = sizeof(T);
        unsigned int size;

    public:
        DynamicArray(){
            size =0;
            data = nullptr;
        }

        DynamicArray(T *items, int count){
            size=0;
            if(count>0){
                data = new T[count];
                for(;size<count;size++){
                    data[size] = items[size];
                }
            }
        }

        ~DynamicArray(){
            delete[] data;
        }

        DynamicArray(int size){
            this->size=size;
            data = new T[size];
            for(int i =0; i<size;i++){
                data[i]=0;
            }
        }

        DynamicArray(const DynamicArray<T> &dynamicArray){
            size=0;
            data = new T[dynamicArray.size];
            for(; this->size<dynamicArray.size; size++){
                data[size] = dynamicArray.data[size];
            }
        }

        T Get(int index){
            if(index>size||index<0){
                throw IndexOutOfRangeException();
            }
            return data[index];
        }

        void Set(int index, T value){
            if(index>size||index<0){throw IndexOutOfRangeException();}
            data[index]=value;
        }

        void  Resize(int newSize){
            T *newData = new T[newSize];
            if(data== nullptr){
                for(int i = 0; i<newSize;i++){
                    newData[i] = 0;
                };
            } else{
                for(int i =0; i<newSize;i++){
                    newData[i]= data[i%size];
                }
            }
            size=newSize;
            delete[] data;
            data = newData;
        }

        int GetSize(){return size;}

        friend ostream& operator<<(ostream &out, DynamicArray dynamicData){
            out<<""<<endl;
            for(int i =0; i< dynamicData.size;i++){
                out<<dynamicData.Get(i);
            }
            out<<""<<endl;
            return out;;
        }

        T& operator[](int i){
            return data[i];
        }

};

#endif //LAB2_DYNAMICARRAY_H
