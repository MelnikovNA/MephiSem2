//
// Created by Stif on 08.05.2023.
//
#include <iostream>
#include "DynamicArray.h"

void isAllRight(bool test){
    if(test){
        cout<<"Test passed"<<endl;
    } else{
        cout<<"Test failed"<<endl;
    }
}

void dynamicArrTestGet(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    DynamicArray<int> *dynamicArray = new DynamicArray(a, 10);
    for (int i = 0; i < 10; ++i) {
        if (dynamicArray->Get(i) != i+1) m = false;
    }
    isAllRight(m);
}

void dynamicArrayTestGetLength(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    DynamicArray<int> *dynamicArray = new DynamicArray(a, 10);
    if (dynamicArray->GetSize() != 10) m = false;
    isAllRight(m);
}

void dynamicArrTestSet(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    DynamicArray<int> *dynamicArray = new DynamicArray(a, 10);
    for (int i = 10; i > 0; --i) {
        dynamicArray->Set(i-1, i-1);
    }
    for (int i = 9; i >= 0; --i) {
        if (dynamicArray->Get(i) != i) m = false;
    }
    isAllRight(m);
}

void dynamicArrTestResize(){
    bool m = true;
    int *a = new int[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i+1;
    }
    DynamicArray<int> *dynamicArray = new DynamicArray(a, 10);
    dynamicArray->Resize(5);
    if (dynamicArray->GetSize() != 5) m = false;
    for (int i = 0; i < 5; ++i) {
        if (dynamicArray->Get(i) != i+1) m = false;
    }
    dynamicArray->Resize(10);
    if (dynamicArray->GetSize() != 10) m = false;
    for (int i; i < 5; ++i) {
        if (dynamicArray->Get(i) != i+1) m = false;
    }
    isAllRight(m);
}

void dynamicArrTests(){
    cout<<"Get: ";
    dynamicArrTestGet();
   cout<<"Resize: ";
    dynamicArrTestResize();
    cout<<"GetSize: ";
    dynamicArrayTestGetLength();
    cout<<"Set: ";
    dynamicArrTestSet();
}

 int main(){
    dynamicArrTests();
    return  0;
}