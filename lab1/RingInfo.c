//
// Created by Stif on 25.02.2023.
//
#include "RingInfo.h"


struct RingInfo* Create(
        size_t size,
        void* (*sum)(void*, void*),
        void* zero,
        void* (*minus)(void*),
        void* (*mult)(void*,void*),
        void* one,
        void* (*new)(void *),
        void* (*strtoval)(char *),
        void *(*valtostr)(void  *);
        )
{
    struct  RingInfo* ringInfo = malloc(sizeof(struct RingInfo));
    ringInfo->size = size;
    ringInfo->sum = sum;
    ringInfo->zero = zero;
    ringInfo->minus = minus;
    ringInfo->mult = mult;
    ringInfo->one = one;
    ringInfo->new=new;
    ringInfo->strtoval=strtoval;
    ringInfo->valtostr=valtostr;
};
