//
// Created by Stif on 26.04.2023.
//

#ifndef LAB2_SEQUENCE_H
#define LAB2_SEQUENCE_H

template<class T>
class Sequence {
public:
    virtual T GetFirst()=0;
    virtual T GetLast()=0;
    virtual T Get(int index) =0;

    virtual  Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual  int GetLength() = 0;

    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;
};


#endif //LAB2_SEQUENCE_H
