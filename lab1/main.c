#include <stdio.h>
#include "ints.h"
#include "RingInfo.h"
#include "Vector.h"


int main() {
    struct RingInfo *ri= Create(sizeof int, &sum_int, the_zero,
            &minus_int, &mult_int, the_one, &new_int, &str_to_val_int, &val_to_str_int);
    struct vectors *vector = from_file(text.txt, *ri);
    print_v(*ri, *vector);
}
