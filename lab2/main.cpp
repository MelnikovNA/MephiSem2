#include <iostream>
#include "ArraySequence.h"
using namespace std;



int main(){
    int a[5] = {1 ,2 ,3 ,4 ,5};
    DynamicArray<int> arr(a, 5);
    DynamicArray<int> arr2(arr);
    arr.Set(1, 333);
    arr.push(13);
    arr.print();
    arr2.print();
    cout<< arr[1];
    return 0;
}