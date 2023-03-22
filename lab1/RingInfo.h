//
// Created by Stif on 14.02.2023.
//
#include <stdlib.h>


#ifndef LAB1_RINGINFO_H
#define LAB1_RINGINFO_H

struct RingInfo
{
    size_t size;
    void* (*sum)(void*, void*);
    void* zero;
    void* (*minus)(void*, void*);
    void* (*mult)(void*, void*);
    void* one;
    void *(*new)(void *);
    void *(*strtoval) (char *str);
    void *(*valtostr)(void  *);
};

#endif //LAB1_RINGINFO_H
