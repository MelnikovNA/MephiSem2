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
    int sizeAr = 0;
    int capacity = 0;
    T* data;
public:
    T operator[](const int i){
        try
        {
            if (sizeAr == 0)
                throw IndexOutOfRangeException(Empty);
            if (i < 0 || i >= sizeAr)
                throw IndexOutOfRangeException(Invalid);
            return this->data[i];
        } catch (IndexOutOfRangeException& e) {
            e.printError();
            return NULL;
        }
    };

    DynamicArray(T* items, int count) : sizeAr(count){
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
        this->sizeAr = 0;
    };

    DynamicArray(DynamicArray<T>& dynamicArray) : sizeAr(dynamicArray.sizeAr){
        capacity = (sizeAr % SIZE == 0) ? SIZE * (sizeAr / SIZE) : SIZE * (sizeAr / SIZE + 1);
        this->data = new T[capacity];
        for (int i = 0; i < this->sizeAr; i++)
        {
            this->data[i] = dynamicArray.get(i);
        }
    };

    ~DynamicArray(){
        if(data != NULL)
            delete [] data;
    };

    void Set(int index, T value){
        try
        {
            if (sizeAr == 0)
                throw IndexOutOfRangeException(Empty);
            if (index < 0 || index > sizeAr)
                throw IndexOutOfRangeException(Invalid);
            data[index] = value;
        } catch (IndexOutOfRangeException& e)
        {
            e.printError();
        }
    }

    void Resize(int newSize){
        capacity = (newSize % SIZE == 0) ? SIZE * (newSize / SIZE) : SIZE * (newSize / SIZE + 1);
        T* newData = new T[capacity];
        for (int i = 0; i < (newSize > sizeAr ? sizeAr : newSize); i++)
        {
            newData[i] = data[i];
        }
        delete data;
        data = newData;
        sizeAr = newSize;
    }

    void InsertAt(T item, int index){
        try{
            if (sizeAr == 0)
                throw IndexOutOfRangeException(Empty);
            if (index < 0 || index >= sizeAr)
                throw IndexOutOfRangeException(Invalid);
            if (capacity == sizeAr + 1){
                capacity += SIZE;
                T* temp = new T[capacity];
                temp[index] = item;
                for (int i = 0; i < index; i++)
                {
                    temp[i] = this->data[i];
                }
                for (int i = index + 1; i < this->sizeAr + 1; i++)
                {
                    temp[i] = this->data[i - 1];
                }
                delete this->data;
                this->data = temp;
                (this->sizeAr)++;
            }
            else
            {
                for (int i = sizeAr; i > index; i--)
                {
                    data[i] = data[i - 1];
                }
                data[index] = item;
                sizeAr++;
            }
        } catch (IndexOutOfRangeException& e) {
            e.printError();
        }
    };

    DynamicArray<T>* Concat(DynamicArray<T>& lst){
        T* newData = new T[this->sizeAr + lst.getSize() + 1];
        for (int i = 0; i < this->sizeAr; i++)
        {
            newData[i] = this->data[i];
        }
        for (int i = 0; i < lst.getSize(); i++)
        {
            newData[i + this->sizeAr] = lst.get(i);
        }
        DynamicArray<T>* nw = new DynamicArray(newData, this->sizeAr + lst.getSize() + 1);
        delete[] newData;
        return nw;
    };

    int GetSize(){return this->sizeAr;};

    T Get(int index){
        try
        {
            if (sizeAr == 0)
                throw IndexOutOfRangeException(Empty);
            if (index >= sizeAr || index < 0)
                throw IndexOutOfRangeException(Invalid);
            return this->data[index];
        } catch (IndexOutOfRangeException& e) {
            e.printError();
            return NULL;
        }
    };

    void DeleteIndex(int index){
        try
        {
            if (sizeAr == 0)
                throw IndexOutOfRangeException(Empty);
            if (index < 0 || index >= sizeAr)
                throw IndexOutOfRangeException(Invalid);
            for (int i = sizeAr; i > index; i--){
                data[i] = data[i - 1];
            }
            sizeAr--;
            if (sizeAr + SIZE == capacity){
                capacity -= SIZE;
                T* temp = new T[capacity];
                for (int i = 0; i < sizeAr; i++){
                    temp[i] = this->data[i];
                }
                delete this->data;
                this->data = temp;
            }
        } catch (IndexOutOfRangeException& e) {
            e.printError();
        }
    }

    DynamicArray<T>* GetSubAr(int startIndex, int fin){
        try{
            if (startIndex < 0 || startIndex >= sizeAr || fin >= sizeAr || fin < 0 || startIndex > fin)
                throw IndexOutOfRangeException(Invalid);
            T* ar = new T[fin - startIndex + 1];
            for (int i = startIndex; i <= fin; i++)
            {
                ar[i - startIndex] = data[i];
            }
            DynamicArray<T>* retval = new DynamicArray<T>(ar, fin - startIndex + 1);
            delete[] ar;
            return retval;
        } catch (IndexOutOfRangeException& e) {
            e.printError();
            return NULL;
        }
    }

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
