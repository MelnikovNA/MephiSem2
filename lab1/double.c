//
// Created by Stif on 22.03.2023.
//

#include <stdlib.h>
#include <stdio.h>
#define MAX_DOUBLE_LEN 100

void *new_double(void *float_ptr){
    double *res = malloc(sizeof(double ));
    *res =*(double*)float_ptr;
    return (void*)res;
}

void* sum_double(void* a1, void* a2){
    double* el1 = (double*)a1;
    double* el2 = (double *)a2;
    double* res = malloc(sizeof(double));
    *res = *el1+*el2;
    return (void*) res;
}

/*void* minus_double(void* a1){
    double* el = (double*)a1;
    double*res = malloc(sizeof(double));
    *res = *el* (-1);
    return (void*)res;
}*/

void* mult_double(void* a1,void* a2){
    double* el1 = (double*)a1;
    double* el2 = (double*)a2;
    double* res = malloc(sizeof(double));
    *res = (*el1)*(*el2);
    return (void*) res;
}

void *str_to_val_double(char *str){
    errno=0;
    char *end_ptr=NULL;
    double res = strtod(str, &end_ptr);
    if(errno==EINVAL){
        return NULL;
    }
    if (end_ptr==NULL || *end_ptr!='\0') {
        // out of bounds or wrong characters in string
        return NULL;
    }
    double v = (double)res;
    return new_double((void*)&v);
}

char *val_to_str_double(void *v){
    char *str = calloc(1, MAX_DOUBLE_LEN);
    double *i = (double *)v;
    snprintf(str, MAX_DOUBLE_LEN, "%.6g", *i);
    return str;
}