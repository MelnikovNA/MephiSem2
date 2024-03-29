//
// Created by Stif on 06.05.2023.
//

#ifndef LAB2_ARRAYSEQUENCE_H
#define LAB2_ARRAYSEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"

using namespace std;

template <class T>
class ArraySequence : Sequence<T>
{
    DynamicArray<T> *data;
public:
    T operator[](const int index)
    {
        return data->Get(index);
    };

    ArraySequence(T* items, int count)
    {
        data = new DynamicArray<T>(items, count);
    };

    ArraySequence()
    {
        data = new DynamicArray<T>();
    };

    ArraySequence(DynamicArray<T> &list)
    {
        data = new DynamicArray<T>(list);
    };

    ~ArraySequence()
    {
        delete  data;
    }

    void Append(T item) override{
        data->Resize(GetLength()+1);
        data->Set(GetLength()-1, item);
    };

    void Prepend(T item) override{
        data->Resize(GetLength()+1);
        for (int i = data->GetSize()-1; i > 0; --i) {
            data->Set(i, data->Get(i-1));
        }
        data->Set(0, item);
    };

    void InsertAt(T item, int index) override
    {
        data->Set(index, item);
    };

    T GetFirst() override
    {
        if(data->GetSize()==0)throw IndexOutOfRangeException(Empty);
        return data->Get(0);
    };

    T GetLast() override
    {
        if(data->GetSize()==0)throw IndexOutOfRangeException(Empty);
        return data->Get(data->GetSize()-1);
    };

    T Get(int index) override
    {
        return data->Get(index);
    };

    int GetLength() override
    {
        return data->GetSize();
    }

    void Set(int index, T value) override
    {
        data->Set(index, value);
    }

    void Resize(int newSize)
    {
        data->Resize(newSize);
    }

    DynamicArray<T>* GetData()
    {
        return data;
    };

    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex)
    {
        if(data->GetSize() == 0 || startIndex<0 || endIndex<0
           || startIndex>endIndex || endIndex > data->GetSize() ) throw IndexOutOfRangeException(Empty);
        T *arr = new T[endIndex-startIndex];
        for (int i = 0; i < endIndex-startIndex; ++i) {
            arr[i] =Get(startIndex+i);
        }
        auto arraySequence = new ArraySequence<T>(arr, endIndex-startIndex);
        return arraySequence;
    };

    ArraySequence<T>* Concat(ArraySequence<T>* list)
    {
        return new ArraySequence(*data->concat(*list->getData()));
    };
};


#endif //LAB2_ARRAYSEQUENCE_H
