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

struct Vector3* Sum(struct Vector3* v1, struct Vector3* v2);
void* Mult(struct Vector3* v1, struct Vector3* v2);
struct Vector3* MultSc(void* scalar, struct Vector3* v);

#endif //LAB1_VECTOR_H
