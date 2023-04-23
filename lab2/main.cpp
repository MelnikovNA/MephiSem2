#include <iostream>
#include "ArraySequence.h"
using namespace std;



int main(){
    DynamicArray<int> arr(5);
    int size = arr.GetSize();
    arr.Set(0, 1);
    cout<<size;
    return 0;
}