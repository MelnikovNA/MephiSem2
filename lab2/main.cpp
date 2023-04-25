#include <iostream>
#include "ArraySequence.h"
using namespace std;
using namespace da;


int main(){
    int a[5] = {1 ,2 ,3 ,4 ,5};
    DynamicArray<int> arr(a, 5);
    DynamicArray<int> arr2(arr);
    arr.Set(1, 333);
    arr.push(13);
    cout<<arr.GetSize()<<endl;
    arr.print();
    arr.Resize(3);
    arr.print();
    cout<<arr2.GetSize()<<endl;
    arr2.print();
    cout<< arr[1];
    return 0;
}