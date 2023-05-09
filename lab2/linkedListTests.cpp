//
// Created by Stif on 08.05.2023.
//
#include "LinkedList.h"
#include <iostream>

void isAllRight(bool test){
    if(test){
        cout<<"Test passed"<<endl;
    } else{
        cout<<"Test failed"<<endl;
    }
}

void linkedListTestGet(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    for (int i = 0; i < 10; ++i) {
        if(linkedList.Get(i)!=i+1) m = false;
    }
    isAllRight(m);
}

void linkedListTestGetFirst(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    if (linkedList.GetFirst() != 1) m = false;
    isAllRight(m);
}

void linkedListTestGetLast(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    if (linkedList.GetLast() != 10) m = false;
    isAllRight(m);
}

void linkedListTestGetLength(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    if(linkedList.GetLenght() !=10) m = false;
    isAllRight(m);
}

void linkedListTestGetSubList(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    LinkedList<int> *linkedList1 = linkedList.GetSubList(2,8);
    if (linkedList1->GetLenght()!= 6) m = false;
    for (int i = 0; i < 6; ++i) {
        if(linkedList1->Get(i)!=i+3) m = false;
    }
    isAllRight(m);
}

void linkedListTestInsertAt(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    LinkedList<int> linkedList = LinkedList<int>(a, 10);
    linkedList.InsertAt(8, 5);
    if(linkedList.Get(6) != 8) m = false;
    isAllRight(m);
}

void linkedListTests(){
    cout<<"GetLength: ";
    linkedListTestGetLength();
    cout<<"Get: ";
    linkedListTestGet();
    cout<<"GetFirst: ";
    linkedListTestGetFirst();
    cout<<"GetSubList: ";
    linkedListTestGetSubList();
    cout<<"GetLast: ";
    linkedListTestGetLast();
    cout<<"InsertAt: ";
    linkedListTestInsertAt();
}

int main(){
    linkedListTests();
    return  0;
}