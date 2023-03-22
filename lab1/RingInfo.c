//
// Created by Stif on 25.02.2023.
//
#include "RingInfo.h"


struct RingInfo* Create(
        size_t size,
        void* (*sum)(void*, void*),
        void* (*mult)(void*,void*),
        void* (*new)(void *),
        void* (*strtoval)(char *),
        char *(*valtostr)(void  *)
        )
{
    struct  RingInfo* ringInfo = malloc(sizeof(struct RingInfo));
    ringInfo->size = size;
    ringInfo->sum = sum;
    ringInfo->mult = mult;
    ringInfo->new=new;
    ringInfo->strtoval=strtoval;
    ringInfo->valtostr=valtostr;
};
