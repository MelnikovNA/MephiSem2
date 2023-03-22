#include "ints.h"
#include "RingInfo.h"
#include "Vector.h"


int main() {
    struct RingInfo *ri= Create(sizeof(int), &sum_int,
            &minus_int, &mult_int,  &new_int,
            &str_to_val_int, &val_to_str_int);
    struct vectors *vector = from_file("C:\\Cprog\\MephiSem2\\lab1\\test", ri);
    //struct Vector3* res = sum_vec(vector->v3s[1], vector->v3s[2], ri);
   //struct Vector3* res = mult(vector->v3s[1], vector->v3s[2], ri); работает не правильно
   //void * res = mult_sc(vector->v3s[1], vector->v3s[2], ri);
    print_v(vector);
    return 0;
}
