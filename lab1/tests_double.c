//
// Created by Stif on 19.04.2023.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "double.h"
#include "Vector.h"

#define ARRAY_SIZE(foo) (sizeof(foo)/sizeof(foo[0]))

struct double_tests{
    double a;
    char *b;
    int want_err;
};

struct double_tests doubles_tests[]={
        {1.1, "1.1", false},
        {-1.1,"-1.1",false},
        {3.3, "!aa", true},
        {0,"0", false}
};

int tests_strs_to_doubles(){
    for(int i=0; i< ARRAY_SIZE(doubles_tests);i++){
        void *res = str_to_val_double(doubles_tests[i].b);
        if(res==NULL){
            if(doubles_tests[i].want_err==false){
                printf("test #%d failed\n",i);
                exit(1);
            }
            continue;
        }
        double r = *((double *)res);
        if(r == doubles_tests[i].a && doubles_tests[i].want_err==true || r!=doubles_tests[i].a && doubles_tests[i].want_err==false){
            printf("test #%d failed\n",i);
            exit(1);
        }
        free(res);
    }
    printf("Tests (str to double) passed\n");
    return 0;
};

int tests_doubles_to_strs(){
    for(int i = 0; i< ARRAY_SIZE(doubles_tests);i++){
        char *res = val_to_str_double((void*)&doubles_tests[i].a);
        if(strcmp(res, doubles_tests[i].b)==0 && doubles_tests[i].want_err == true||
        strcmp(res, doubles_tests[i].b)!=0 && doubles_tests[i].want_err == false){
            printf("test #%d failed\n",i);
            exit(1);
        }
        free(res);
    }
    printf("Tests (double to str) passed\n");
    return 0;
}

int main(){
    tests_strs_to_doubles();
    tests_doubles_to_strs();
    return 0;
}