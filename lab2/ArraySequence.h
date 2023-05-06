//
// Created by Stif on 06.05.2023.
//

#ifndef LAB2_ARRAYSEQUENCE_H
#define LAB2_ARRAYSEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"

using namespace std;

template<class T>
class ArraySequence :Sequence<T>{
private:
    DynamicArray<T> dynamicArray;
public:
    ArraySequence (T* items, int count){
        dynamicArray = DynamicArray<T>(items, count);
    }

    ArraySequence(){
        dynamicArray = DynamicArray<T>();
    }

    ~ArraySequence(){
        delete &dynamicArray;
    }

    ArraySequence(const DynamicArray<T> &data){
        dynamicArray = DynamicArray<T>(data);
    }

    ArraySequence(const ArraySequence<T> &arraySequence){
        dynamicArray = arraySequence.dynamicArray;
    }

    T GetFirst(){
        if(dynamicArray.GetSize()==0) throw IndexOutOfRangeException();
        return dynamicArray.Get(0);
    }

    T GetLast(){
        if(dynamicArray.GetSize()==0) throw IndexOutOfRangeException();
        return dynamicArray.Get(dynamicArray.GetSize()-1);
    }
    T Get(int index){
        if (dynamicArray.GetLength() == 0 || index<0 || index - 1 > dynamicArray.GetLength()) throw IndexOutOfRangeException();
        return dynamicArray.Get(index);
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex){
        if(dynamicArray.GetLength() == 0 ||
        startIndex<0 || endIndex<0||
        startIndex>endIndex ||
        endIndex > dynamicArray.GetLength() ) throw IndexOutOfRangeException();
        T *data = new T[endIndex-startIndex];
        for(int i = 0; i<endIndex-startIndex;i++){
            data[i] = Get(startIndex+i);
        }
        auto arraySequence = new ArraySequence<T>(data, endIndex-startIndex);
        return arraySequence;
    }

    int GetLength(){
        return this->dynamicArray.GetSize();
    }

    void Append(T item){
        dynamicArray.Resize(GetLength()+1);
        dynamicArray.Set(GetLength()-1, item);
    }

    void Prepend(T item){
        dynamicArray.Resize(GetLength());
        for(int i =GetLength()-1; i>0; i--){
            dynamicArray.Set(i, Get(i-1));
        }
        dynamicArray.Set(0, item);
    };

    void InsertAt(T item, int index){
        dynamicArray.Set(index, item);
    }

    Sequence <T>* Concat(Sequence <T> *list) {
        T *data = new T[list->GetLenght() + GetLength() - 2];
        for (int i = 0; i < GetLength() - 1; i++) {
            data[i] = Get(i);
        }
        for (int i = dynamicArray.GetSize(); i < dynamicArray.GetSize() + list->GetLenght(); i++) {
            data[i] = list->Get(i);
        }
        ArraySequence<T> *arraySequence = ArraySequence<T>(data, list->GetLenght() + GetLength());
        return arraySequence;
    }
    void DeletElement(int index){
        if(index<1, index>GetLength()) throw IndexOutOfRangeException();
        int len = GetLength();
        T *data = new T[GetLength()-1];
        for(int i = 0;i <index-1; i++){data[i]= Get(i);};
        for(int i =0; i<GetLength();i++){data[i-1]= Get(i);};
        dynamicArray = DynamicArray<T>(data, len-1);
    };

    friend ostream &operator<<(ostream&out, ArraySequence arraySequence){
        out<<""<<endl;
        for(int i =0; i< arraySequence.GetLength();i++){
            out<<arraySequence.Get(i)<<" ";
        }
        out<<""<<endl;
    };

};


#endif //LAB2_ARRAYSEQUENCE_H
