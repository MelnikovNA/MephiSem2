//
// Created by Stif on 25.02.2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#define MAX_INT_LEN 20

void *new_int(void *int_ptr){
    int *res=malloc(sizeof(int));
    *res=*(int*)int_ptr;
    return (void*)res;
}

void* sum_int(void* a1, void* a2){
    int* el1 = (int*)a1;
    int* el2 = (int *)a2;
    int* res = malloc(sizeof(int ));
    *res = *el1+*el2;
    return (void*) res;
}

/*void* minus_int(void* a1){
    int* el = (int*)a1;
    int*res = malloc(sizeof(int));
    *res = *el* (-1);
    return (void*)res;
}*/

void* mult_int(void* a1,void* a2){
    int* el1 = (int*)a1;
    int* el2 = (int *)a2;
    int* res = malloc(sizeof(int ));
    *res = (*el1)*(*el2);
    return (void*) res;
}

void *str_to_val_int(char *str){
    errno=0;
    char *end_ptr=NULL;
    long res=strtol(str,&end_ptr,10);
    if (errno==EINVAL){
        return NULL;
    }
    int v=(int)res;
    return new_int((void*)&v);
}

char *val_to_str_int(void *v){
    char *str = calloc(1, MAX_INT_LEN);
    int *i=(int *)v;
    snprintf(str, MAX_INT_LEN,"%d", *i);
    return str;
}