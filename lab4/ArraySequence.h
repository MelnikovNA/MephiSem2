//
// Created by Stif on 10.06.2023.
//

#ifndef LAB_4_ARRAYSEQUENCE_H
#define LAB_4_ARRAYSEQUENCE_H

#endif //LAB_4_ARRAYSEQUENCE_H

#include "DynamicArray.h"

template <class T>
class ArraySequence{
private:
    DynamicArray<T> dynamicArray;
public:
    ArraySequence(T a){
        dynamicArray = DynamicArray<T>(a);
    }

    ArraySequence(T* items, int count){
        dynamicArray = DynamicArray<T>(items, count);
    }

    ArraySequence(){
        dynamicArray = DynamicArray<T>();
    }

    ArraySequence(const DynamicArray<T> & list){
        dynamicArray = DynamicArray<T>(list);
    }

    ArraySequence(const ArraySequence<T> &arraySequence){
        dynamicArray = arraySequence.dynamicArray;
    }

    T GetFirst(){
        if(dynamicArray.GetLength() == 0) throw IndexOutOfRange();
        return dynamicArray.Get(0);
    }

    T GetLast(){
        if (dynamicArray.GetLength() == 0) throw IndexOutOfRange();
        return dynamicArray.Get(dynamicArray.GetLength()-1);
    }

    T Get(int index){
        if (dynamicArray.GetLength() == 0 || index<0 || index - 1 > dynamicArray.GetLength()) throw IndexOutOfRange();
        return dynamicArray.Get(index);
    }

    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex){
        if(dynamicArray.GetLength() == 0 || startIndex<0 || endIndex<0
           || startIndex>endIndex || endIndex > dynamicArray.GetLength() ) throw IndexOutOfRange();
        T *arr = new T[endIndex-startIndex];
        for (int i = 0; i < endIndex-startIndex; ++i) {
            arr[i] =Get(startIndex+i);
        }
        auto arraySequence = new ArraySequence<T>(arr, endIndex-startIndex);
        return arraySequence;
    }

    int GetLength(){
        return dynamicArray.GetLength();
    }

    void Append(T item){
        dynamicArray.Resize(GetLength()+1);
        dynamicArray.Set(GetLength()-1, item);
    }

    void Append(T *item){
        Append(*item);
    }
    void Prepend(T item){
        dynamicArray.Resize(GetLength());
        for (int i = GetLength()-1; i > 0; --i) {
            dynamicArray.Set(i, Get(i-1));
        }
        dynamicArray.Set(0, item);
    }

    void InsertAt(T item, int index){
        dynamicArray.Set(index, item);
    }

    ArraySequence<T> *Concat(ArraySequence<T> *list){
        T *arr = new T[list->GetLength() + GetLength() - 2];
        for (int i = 0; i < GetLength(); ++i) {
            arr[i] = Get(i);
        }
        for (int i = dynamicArray.GetLength(); i < dynamicArray.GetLength() + list->GetLength(); ++i) {
            arr[i] = list->Get(i);
        }
        ArraySequence<T> *arraySequence = ArraySequence<T>(arr, list->GetLength()+GetLength());
        return arraySequence;
    }

    void changeElements(int index1, int index2){
        T item = Get(index1);
        InsertAt(Get(index2), index1);
        InsertAt(item, index2);
    }

    void deleteElement(int index){
        if(index<1, index>GetLength()) throw IndexOutOfRange();
        int len = GetLength();
        T *a = new T[GetLength()-1];
        int i = 0;
        for (; i < index-1; ++i) {
            a[i] = Get(i);
        }
        for (; i < GetLength(); ++i) {
            a[i-1] = Get(i);
        }
        dynamicArray = DynamicArray<T>(a, len-1);
    }

    void deleteLast(){
        T *a = new T[GetLength()-1];
        for (int i = 0; i < GetLength()-1; ++i) {
            a[i] = Get(i);
        }
        dynamicArray = DynamicArray<T>(a, GetLength()-1);
    }

    friend std::ostream& operator<<(std::ostream &out, ArraySequence arraySequence){
        out<<""<<std::endl;
        for (int i = 0; i < arraySequence.GetLength(); ++i) {
            out<<arraySequence.Get(i)<<" ";
        }
        out<<""<<std::endl;
        return out;
    }
};
