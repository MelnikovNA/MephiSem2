//
// Created by Stif on 06.05.2023.
//

#ifndef LAB2_LINKEDLIST_H
#define LAB2_LINKEDLIST_H

#include <iostream>
#include "IndexOutOfRangeException.h"

using namespace std;

template<class T>
class Element{
public:
    T data;
    Element<T> *next;
    Element<T>*prev;
};

template<class T>
class LinkedList{
private:
    int len =0;
    Element<T> *head = nullptr;
    Element<T>*end = nullptr;

public:

    LinkedList(){
        head = NULL;
        end = NULL;
    };

    void Prepend(T *item){
        Element<T> *elem = new Element<T>;
        elem->data=item;
        elem->next = nullptr;
        elem->prev = nullptr;
        len++;
        if(head== nullptr){
            head=elem;
            end = elem;
            return;
        };
        elem->next = head;
        head = elem;
    };

    void Append(T item){
        Element<T> *elem = new Element<T>;
        elem->data = item;
        elem->next= nullptr;
        elem->prev=end;
        len++;
        if(head == nullptr){
            head = elem;
            end = elem;
            return;
        };
        end->next=elem;
        end = elem;
    };


    LinkedList(T *items, int count){
        for(int i =0; i<count;i++) Append(items[i]);
    };

    LinkedList(const LinkedList<T> &list){
        Element<T>*elem = list.head;
        for(int i =0; i<list.len;i++){
            Append(elem->data);
            elem=elem->next;
        };
    };

    ~LinkedList(){
        Element<T>*elem1 = head;
        Element<T>*elem2 = head;
        while(elem1){
            elem2 = elem1;
            elem1 = elem1->next;
            delete elem1;
        };
    };

    T GetFirst(){
        if(head== nullptr)throw IndexOutOfRangeException();
        return head->data;
    };

    T GetLast(){
        if(head== nullptr)throw IndexOutOfRangeException();
        return end->data;
    };

    T Get(int index){
        if(head== nullptr)throw IndexOutOfRangeException();
        if(index>len-1||index<0) throw IndexOutOfRangeException();
        Element<T> *elem = new Element<T>;
        elem = head;
        for(int i =0; i< index;i++){
            elem=elem->next;
        }
        return elem->data;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex){
        if(head== nullptr)throw IndexOutOfRangeException();
        if(endIndex>len-1||startIndex>len-1||startIndex<0||endIndex<0||startIndex==endIndex)throw IndexOutOfRangeException();
        if(startIndex>endIndex){
            int a = startIndex;
            startIndex = endIndex;
            endIndex = a;
        };
       Element<T> *elem = new Element<T>;
       elem = head;
       for(int i =0; i<startIndex;i++){
           elem=elem->next;
       };
       LinkedList<T> *list = new LinkedList<T>;
       for(int i =0;i < endIndex-startIndex; i++){
           list->Append(elem->data);
           elem=elem->next;
       };
       list->end = elem;
        return list;
    };

    int GetLenght(){return  len;};

    void InsertAt(T item, int index){
        if(head== nullptr)throw IndexOutOfRangeException();
        if(index>len-1||index<0) throw IndexOutOfRangeException();
        Element<T> *elem = new Element<T>;
        elem = head;
        for(int i =0; i<index;i++){
            elem = elem->next;
        };
        Element<T>* elem2 = new Element<T>;
        elem2->data=item;
        elem2->next=elem->next->next;
        elem->next=elem2;
    }

    LinkedList<T>* Concat(LinkedList<T> *list){
        LinkedList<T>*linkedList = new LinkedList<T>;
        linkedList->head = head;
        linkedList->end = end;
        linkedList->end->next = list->head;
        linkedList->end = list->end;
        len = len+list->len;
        return linkedList;
    }
};

#endif //LAB2_LINKEDLIST_H
