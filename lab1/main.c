#include <stdio.h>
#include "ints.h"
#include "RingInfo.h"
#include "Vector.h"

struct int_vector{
    int x,y,z;
};

struct int_vector def[]={
        {0,1,2},
        {0,1,2},
        {0,1,2},
        {0,1,2},
        {0,1,2},
};

int main() {
    struct RingInfo *ri= Create(sizeof int, &sum_int, the_zero, &minus_int, &mult_int, the_one,&new_int);
}
