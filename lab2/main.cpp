#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main(){
    int a[5] = {1, 2 ,3 ,4,5};
    DynamicArray<int> data(a, 5);
    cout<<data[1];
    return 0;
}
