#include <stdio.h>
#include "ints.h"
#include "RingInfo.h"
#include "Vector.h"
#include "double.h"

int main() {
    int test;
    struct RingInfo* ri;
    struct vectors * vector = NULL;
    test = 2;
    switch (test) {
        case 1:
            ri= Create(sizeof(int), &sum_int,&mult_int,  &new_int,
                       &str_to_val_int, &val_to_str_int);
            vector = from_file("C:\\Cprog\\MephiSem2\\lab1\\test", ri);
            print_v(vector);
            break;
        case 2:
            ri = Create(sizeof(double ), &sum_double, &mult_double,
                        &new_double, &str_to_val_double, &val_to_str_double);

            vector = from_file("C:\\Cprog\\MephiSem2\\lab1\\test", ri) ;
            void *res = mult_sc(vector->v3s[0], vector->v3s[1], ri);
            print_val(res, ri);
            print_v(vector);
            break;
    }
    return 0;
}
