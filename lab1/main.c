#include "ints.h"
#include "RingInfo.h"
#include "Vector.h"


int main() {
    struct RingInfo *ri= Create(sizeof(int), &sum_int,
            &minus_int, &mult_int,  &new_int,
            &str_to_val_int, &val_to_str_int);
    struct vectors *vector = from_file("C:\\Cprog\\MephiSem2\\lab1\\test", ri);
    print_v(ri, vector);
    return 0;
}
