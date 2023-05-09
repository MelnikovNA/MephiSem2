//
// Created by Stif on 06.05.2023.
//

#ifndef LAB2_LINKEDLISTSEQUENCE_H
#define LAB2_LINKEDLISTSEQUENCE_H

#include "IndexOutOfRangeException.h"
#include "LinkedList.h"
#include "Sequence.h"

template<class T>
class LinkedListSequence : Sequence<T>
{
    LinkedList<T> *data;
public:
    T operator[](const int index)
    {
        return data->get(index);
    };

    LinkedListSequence(T* items, int count)
    {
        data = new LinkedList<T>(items, count);
    };

    LinkedListSequence()
    {
        data = new LinkedList<T>();
    };

    LinkedListSequence(LinkedList<T> &list)
    {
        data = new LinkedList<T>(list);
    };

    ~LinkedListSequence()
    {
        delete data;
    }

    void append(T item) override
    {
        data->append(item);
    };

    void prepend(T item) override
    {
        data->prepend(item);
    };

    void insertAt(T item, int index) override
    {
        data->insertAt(item, index);
    };

    void deleteAt(int index)
    {
        data->deleteIndex(index);
    }

    T getFirst() override
    {
        return data->getFirst();
    };

    T getLast() override
    {
        return data->getLast();
    };

    T get(int index) override
    {
        return data->get(index);
    };

    int getLength() override
    {
        return data->getLength();
    };

    LinkedList<T>* getData()
    {
        return data;
    };

    void set(int index, T value) override
    {
        data->set(index, value);
    }

    LinkedListSequence<T>* getSubsequence(int startIndex, int endIndex)
    {
        LinkedList<T>* copy = data->getSubList(startIndex, endIndex);
        LinkedListSequence<T>* retval = new LinkedListSequence(*copy);
        delete copy;
        return retval;
    };

    LinkedListSequence<T>* concat(LinkedListSequence<T>* list)
    {
        return new LinkedListSequence(*data->concat(*list->getData()));
    };
};

#endif //LAB2_LINKEDLISTSEQUENCE_H
