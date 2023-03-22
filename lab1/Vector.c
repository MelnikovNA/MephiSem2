//
// Created by Stif on 14.02.2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "RingInfo.h"
#include "Vector.h"

struct Vector3 *the_zero = NULL;


void* mult(struct Vector3* v1, struct Vector3* v2, struct RingInfo *ri){
    struct Vector3* res = malloc((sizeof(struct Vector3)));
    res->x = ri->mult(v1->x, v2->x);
    res->y = ri->mult(v1->y, v2->y);
    res->z = ri->mult(v1->z, v2->z);
    return  res;
};

struct Vector3* sum_vec(struct Vector3* v1, struct Vector3* v2, struct RingInfo *ri){
    struct Vector3* res = malloc(sizeof(struct Vector3));
    res->x=ri->sum(v1->x, v2->x);
    res->y=ri->sum(v1->y, v2->y);
    res->z=ri->sum(v1->z, v2->z);
    return res;
}

struct Vector3* mult_sc(struct Vector3*v1, struct Vector3*v2, struct RingInfo *ri){
    struct Vector3* temp_res = mult(v1, v2, ri);
    void* res = ri->sum(temp_res->x, temp_res->y);
    res = ri->sum(res, temp_res->z);
    return res;
}


void raise(char *s) {
    fprintf(stderr, "error: %s\n strerror:\n%s", s, strerror(errno));
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
        vs->v3s[vs->len-1] = new_vector;
    }
}
void print_val(void * v, struct RingInfo* ri){
    if(v==NULL){
        return;
    }
    char *res = ri->valtostr(v);
    printf("%s", res);
    free(res);
    return;
}

void print_v3(struct  Vector3*vs, struct RingInfo *ri){
    if(vs == NULL){
        return;
    };
    char *vx = ri->valtostr(vs->x);
    char *vy = ri->valtostr(vs->y);
    char *vz = ri->valtostr(vs->z);
    printf("%s %s %s\n", vx, vy, vz);
    free(vx);
    free(vy);
    free(vz);
}

void print_v( struct vectors *vs){
    if(vs==NULL){
        return ;
    }
    for(int i =0; i<vs->len;i++){
        print_v3(vs->v3s[i], vs->ringInfo);
    }
}
