//
// Created by Stif on 14.02.2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "RingInfo.h"
#include "Vector.h"

struct Vector3 *the_zero = NULL;

struct Vector3 *zero(struct RingInfo ri) {
    if (!the_zero) {
        int zero_val = 0;
        the_zero = malloc(sizeof(struct Vector3));
        the_zero->x = ri->new(&zero_val);
        the_zero->y = ri->new(&zero_val);
        the_zero->z = ri->new(&zero_val);
    }
    return the_zero;
};

void *GetX(struct Vector3 *vect) {
    if (vect) {
        return vect->x;
    }

}

void *GetY(struct Vector3 *vect) {
    if (vect) {
        return vect->y;
    }
}

void *GetZ(struct Vector3 *vect) {
    if (vect) {
        return vect->z;
    }
}

// v=Sum(a,b,ri->sum);


/*
struct Vector3* Sum(struct Vector31* v1, struct Vector31* v2, void* (*sum)(void*,void*))
{
    struct Vector3* result = malloc(sizeof(struct Vector3));
    result->x = sum(v1->x, v2->x); //???? не определен +
    result->y = sum(v1->y, v2->y); //???? не определен +
    result->z = sum(v1->z, v2->z); //???? не определен +
    return result;
}
*/



void raise(char *s) {
    fprintf(stderr, "error: %s strerror:%s", s, strerror(errno));
    exit(1);
}

/*int scanf_detail(FILE *file, struct Vector3 *vec, struct RingInfo *ri) {
    int ret = fscanf(file, "%s%s%s", x, y, z);

    if (ret == EOF) {
        if (feof(file)) {
            return RET_EOF;
        }
        fprintf(stderr, "could not read file:(%i) %s\n", errno, strerror(errno));
        return RET_ERROR;
    }

    if (ret != 3) {
        fprintf(stderr, "syntax error in input file\n");
        return RET_ERROR;
    }

    vec->x = ri->strtoval(x);
    vec->y = ri->strtoval(y);
    vec->z = ri->strtoval(z);

    return RET_OK;
}*/


struct vectors *from_file(char *file_name, struct RingInfo *ri, int *count) {
    struct vectors *vs = calloc(1, sizeof(struct vectors));
    char x[100], y[100], z[100];
    vs->len = 0;
    vs->capacity = 0;
    FILE *f = fopen(file_name, "r");
    if (f == NULL) {
        fprintf(stderr, "could not read file %s:(%i) %s\\n",
                file_name, errno, strerror(errno));
        return NULL;
    }
    while (1) { //read line from file
        int ret = fscanf(file, "%s%s%s", x, y, z);
        void *vx = ri->strtoval(x);
        if (vx == NULL) {
            raise("x wrong value");
        }
        void *vy = ri->strtoval(y);
        if (vy == NULL) {
            raise("x wrong value");
        }
        void *vz = ri->strtoval(z);
        if (vz == NULL) {
            raise("x wrong value");
        }
    }
    vs->len++;
    if (vs->capacity < vs->len) {
        capacity += 100;
        vs->v3s = realloc(vs->v3s, ....); // from capacity
    }
    struct Vector3 *new_vector = {
            x, y, z
    };

    vs->v3s[len] = new_vector;

}
