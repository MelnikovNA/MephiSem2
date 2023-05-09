//
// Created by Stif on 07.05.2023.
//
#include "ArraySequence.h"
#include <iostream>

using namespace std;

void isAllRight(bool test){
    if(test){
        cout<<"Test passed"<<endl;
    } else{
        cout<<"Test failed"<<endl;
    }
}
void arraySequenceTestGetFirst(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    if(arraySequence.GetFirst()!=1) m = false;
    isAllRight(m);
}

void arraySequenceTestGetLast(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    if(arraySequence.GetFirst()!=10) m = false;
    isAllRight(m);
}

void arraySequenceTestGet(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    for (int i = 0; i < 10; ++i) {
        if(arraySequence.Get(i) != i+1) m = false;
    }
    isAllRight(m);
}

void arraySequenceTestGetSubSequence(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> *arraySequence = new ArraySequence(a, 10);
    ArraySequence<int> *arraySequence1 = arraySequence->GetSubsequence(2, 8);
    if(arraySequence1->GetLength() != 6) m = false;
    for (int i = 0; i < 6; ++i) {
        if(arraySequence1->Get(i) != i+3) m = false;
    }
    isAllRight(m);
}

void arraySequenceTestAppend(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    arraySequence.Append(11);
    if(arraySequence.GetLength() != 11) m = false;
    for (int i = 0; i < 11; ++i) {
        if(arraySequence.Get(i) != i+1) m = false;
    }
    isAllRight(m);
}

void arraySequenceTestPrepend(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> *arraySequence = new ArraySequence(a, 10);
    arraySequence->Prepend(0);
    if(arraySequence->GetLength() != 11) m = false;
    for (int i = 0; i < 11; ++i) {
        if(arraySequence->Get(i) != i) m = false;
    }
    isAllRight(m);
}

void arraySequenceTestInsertAt(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    arraySequence.InsertAt(5, 2);
    if(arraySequence.Get(2)!=5) m = false;
    isAllRight(m);
}

void arraySequenceTestDeleteElements(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    ArraySequence<int> arraySequence = ArraySequence<int>(a, 10);
    arraySequence.DeleteAt(2);
    if(arraySequence.GetLength()!=9) m = false;
    for (int i = 0; i < 2; ++i) {
        if(arraySequence.Get(i)!=i+1) m = false;
    }
    isAllRight(m);
}

void arraySequenceTestAll(){
    arraySequenceTestGetFirst();
    arraySequenceTestGetLast();
    arraySequenceTestGet();
    arraySequenceTestGetSubSequence();
    arraySequenceTestInsertAt();
    arraySequenceTestPrepend();
    arraySequenceTestDeleteElements();
    arraySequenceTestAppend();
}

int main(){
    cout<<"Append : ";
    arraySequenceTestAll();
}