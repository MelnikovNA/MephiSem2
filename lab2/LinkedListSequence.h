//
// Created by Stif on 06.05.2023.
//

#ifndef LAB2_LINKEDLISTSEQUENCE_H
#define LAB2_LINKEDLISTSEQUENCE_H

#include "IndexOutOfRangeException.h"
#include "LinkedList.h"
#include "Sequence.h"

template <class T>
class LinkedListSequence : Sequence<T>{
private:
    LinkedList<T> linkedList;
public:
    LinkedListSequence (T* items, int count){
        linkedList = LinkedList(items, count);
    }

    LinkedListSequence (){
        linkedList = LinkedList();
    }

    ~LinkedListSequence(){
        delete &linkedList;
    }

    LinkedListSequence(const LinkedList <T> & list ){
        linkedList = LinkedList(list);
    }

    T GetFirst(){
        if(linkedList.len == 0)
            throw IndexOutOfRangeException();
        return linkedList.GetFirst();
    }

    T GetLast(){
        if(linkedList.GetLength() == 0)
            throw IndexOutOfRangeException();
        return linkedList.GetLast();
    }

    Element<T> *GetElement(int index){
        if (linkedList.GetLength() == 0)
            throw 
;
        return linkedList.GetElement(index);
    }

    T Get(int index){
        if (linkedList.GetLength() == 0)
            throw 
;
        return linkedList.Get(index);
    }

    LinkedListSequence<T>* GetSubListSequence(int startIndex, int endIndex){
        LinkedList<T> *linkedList1 = linkedList.GetSubList(startIndex, endIndex);
        LinkedListSequence<T> *linkedListSequence = LinkedListSequence(linkedList1);
        return linkedListSequence;
    }

    int GetLength(){
        return linkedList.GetLength();
    }

    void Append(T item){
        linkedList.Append(item);
    }

    void Prepend(T item){
        linkedList.Prepend(item);
    }

    void InsertAt(T item, int index){
        linkedList.InsertAt(item, index);
    }

    LinkedListSequence<T>* Concat(Sequence <T> *list){
        LinkedList<T> linkedList1 = linkedList.Concat(list);
        LinkedListSequence<T> *linkedListSequence = LinkedList<T>(linkedList1);
        return linkedListSequence;
    }
};


#endif //LAB2_LINKEDLISTSEQUENCE_H
