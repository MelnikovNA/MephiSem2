//
// Created by Stif on 14.02.2023.
//
#include <stdlib.h>
#include "RingInfo.h"

#ifndef LAB1_VECTOR_H
#define LAB1_VECTOR_H

//struct Vector3;
struct Vector3{
    void* x;
    void* y;
    void* z;
};

struct vectors{
    struct RingInfo* ringInfo;
    size_t len;
    size_t  capacity;
    struct Vector3 **v3s;
};

struct vectors *from_file(char *file_name, struct RingInfo *ri);
void print_v( struct vectors *vs);
void print_v3(struct  Vector3*vs, struct RingInfo *ri);
void print_val(void * v, struct RingInfo* ri);

struct Vector3* mult_sc(struct Vector3*v1, struct Vector3*v2, struct RingInfo *ri);
struct Vector3* sum_vec(struct Vector3* v1, struct Vector3* v2, struct RingInfo *ri);
void* mult(struct Vector3* v1, struct Vector3* v2, struct RingInfo *ri);

#endif //LAB1_VECTOR_H
