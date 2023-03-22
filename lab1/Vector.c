//
// Created by Stif on 14.02.2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "RingInfo.h"
#include "Vector.h"

struct Vector3 *the_zero = NULL;

/*
struct Vector3 *zero(struct RingInfo ri) {
    if (!the_zero) {
        int zero_val = 0;
        the_zero = malloc(sizeof(struct Vector3));
        the_zero->x = ri->new(&zero_val);
        the_zero->y = ri->new(&zero_val);
        the_zero->z = ri->new(&zero_val);
    }
    return the_zero;
};*/

// v=Sum(a,b,ri->sum);

/*
struct Vector3* Sum(struct Vector31* v1, struct Vector31* v2, void* (*sum)(void*,void*))
{
    struct Vector3* result = malloc(sizeof(struct Vector3));
    result->x = sum(v1->x, v2->x);
    result->y = sum(v1->y, v2->y);
    result->z = sum(v1->z, v2->z);
    return result;
}*/


void raise(char *s) {
    fprintf(stderr, "error: %s strerror:%s", s, strerror(errno));
    exit(1);
}

struct vectors *from_file(char *file_name, struct RingInfo *ri) {
    struct vectors *vs = calloc(1, sizeof(struct vectors));
    vs->ringInfo=ri;
    struct Vector3 *new_vector = NULL;
    char x[100], y[100], z[100];
    vs->len = 0;
    vs->capacity = 0;
    FILE *f = fopen(file_name, "r");
    if (f == NULL) {
        fprintf(stderr, "could not read file %s:(%i) %s\n",
                file_name, errno, strerror(errno));
        return NULL;
    }
    while (1) { //read line from file
        if(feof(f)){
            return vs;
        }
        int ret = fscanf(f, "%s%s%s", x, y, z);
        if(ret != 3){
            fprintf(stderr, "format invalid %s\n",
                    file_name);
            return NULL;
        }
        void *vx = ri->strtoval(x);
        if (vx == NULL) {
            raise("x wrong value");
        }
        void *vy = ri->strtoval(y);
        if (vy == NULL) {
            raise("y wrong value");
        }
        void *vz = ri->strtoval(z);
        if (vz == NULL) {
            raise("z wrong value");
        }

        vs->len++;
        if (vs->capacity < vs->len) {
            vs->capacity += 100;
            vs->v3s = realloc(vs->v3s, vs->capacity* sizeof(void*));
        }
        new_vector= malloc(1*sizeof(struct Vector3));
        new_vector->x = vx;
        new_vector->y = vy;
        new_vector->z = vz;
        vs->v3s[vs->len] = new_vector;
    }
}

void print_v( struct vectors *vs){
    if(vs==NULL){
        return ;
    }
    for(int i =1; i<=vs->len;i++){
        char *vx = vs->ringInfo->valtostr(vs->v3s[i]->x);
        char *vy = vs->ringInfo->valtostr(vs->v3s[i]->y);
        char *vz = vs->ringInfo->valtostr(vs->v3s[i]->z);
        printf("%s %s %s\n", vx, vy, vz);
        free(vx);
        free(vy);
        free(vz);
    }
}
