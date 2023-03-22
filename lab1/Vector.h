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

//vs
//vs->v3s[3]->x=10
struct vectors{
    struct RingInfo* ringInfo;
    size_t len;
    size_t  capacity;
    struct Vector3 **v3s;
};

struct Vector3* E_1(struct RingInfo* ringInfo);
struct Vector3* E_2(struct RingInfo* ringInfo);
struct Vector3* E_3(struct RingInfo* ringInfo);
struct Vector3* Zero(struct RingInfo* ringInfo);
struct Vector3* From(struct RingInfo* ringInfo, int* values);

void *GetX(struct Vector3* vect);
void *GetY(struct Vector3* vect);
void *GetZ(struct Vector3* vect);

struct vectors *from_file(char *file_name, struct RingInfo *ri);
int print_v(struct RingInfo *ri, struct vectors *vs);

struct Vector3* sum(struct Vector3* v1, struct Vector3* v2, struct RingInfo *ri);
void* mult(struct Vector3* v1, struct Vector3* v2, struct RingInfo *ri);
struct Vector3* multSc(void* scalar, struct Vector3* v, struct RingInfo *ri);

#endif //LAB1_VECTOR_H
