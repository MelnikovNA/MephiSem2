//
// Created by Stif on 19.04.2023.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "double.h"
#include "Vector.h"

#define ARRAY_SIZE(foo) (sizeof(foo)/sizeof(foo[0]))

struct test_vector3{
    double x;
    double y;
    double z;
};

struct vector_sum{
    struct test_vector3 a;
    struct  test_vector3 b;
    struct  test_vector3 res;
    int want_err;
};

struct vector_sum sum_tests[]={
        {{ 1.1,  1.1,  1.1},
                { 1.1,1.1,1.1},
                {2.2,2.2, 2.2},
                false},

        {{1.12,2.31, 3.0},
                {3.15,2.52, 1.3},
                {4.27,4.83, 4.3},
                false},

        {{-10.1,1.13, 4.1},
                {1.2,-1.11, 1.3},
                {-8.9,0.019999999999999796, 5.3999999999999995},
                false},

        {{-10.1,1.2, 1.3},
                {1.13,1.333, 1.22},
                {-900,2, 2},
                true},
};

struct vector_mult_sc{
    struct test_vector3 a;
    struct test_vector3 b;
    double res;
    int want_err;
};

struct vector_mult_sc mult_sc_test[]={
        {{ 1.1,  1.1,  1.1},
                { 1.1,1.1,1.1},
                3.6300000000000008,
                false},

        {{1.12,2.31, 3.0},
                {3.15,2.52, 1.3},
                13.2492,
                false},

        {{-10.1,1.13, 4.1},
                {1.2,-1.11, 1.3},
                -8.0443,
                false},

        {{-10.1,1.2, 1.3},
                {1.13,1.333, 1.22},
                -999,
                true},
};

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
};

int test_sum(struct RingInfo* ri){
    struct Vector3 a,b;
    for(int i =0; i< ARRAY_SIZE(sum_tests);i++){
        a.x = &sum_tests[i].a.x;
        a.y = &sum_tests[i].a.y;
        a.z = &sum_tests[i].a.z;

        b.x = &sum_tests[i].b.x;
        b.y = &sum_tests[i].b.y;
        b.z = &sum_tests[i].b.z;

        struct Vector3 *sum = sum_vec(&a, &b, ri);


        bool comp = *(double *) sum->x == sum_tests[i].res.x  &&
                                *(double *) sum->y == sum_tests[i].res.y &&
                                *(double *) sum->z == sum_tests[i].res.z;

        if(comp==true && sum_tests[i].want_err==true ||
            comp==false&&sum_tests[i].want_err==false){
            printf("test #%d failed\n",i);
            exit(1);
        }
    }
    printf("Tests (double sum vectors ) passed\n ");
    return 0;
};

int test_mult_sc(struct RingInfo *ri){
    struct Vector3 a,b;
    for(int i =0; i< ARRAY_SIZE(mult_sc_test);i++){
        a.x=&mult_sc_test[i].a.x;
        a.y=&mult_sc_test[i].a.y;
        a.z=&mult_sc_test[i].a.z;

        b.x=&mult_sc_test[i].b.x;
        b.y=&mult_sc_test[i].b.y;
        b.z=&mult_sc_test[i].b.z;
        void* res = mult_sc(&a,&b,ri);
        double r = *((double *)res);
        if(r==mult_sc_test[i].res && mult_sc_test[i].want_err==true ||
           r!=mult_sc_test[i].res && mult_sc_test[i].want_err==false){
            printf("test #%d failed\n",i);
            exit(1);
        }
    }
    printf("Tests (double mult_sc vectors ) passed\n ");
    return 0;
}

int main(){
    struct RingInfo *ri;
    tests_strs_to_doubles();
    tests_doubles_to_strs();
    ri = Create(sizeof(double ), &sum_double, &mult_double,
                &new_double, &str_to_val_double, &val_to_str_double);
    test_sum(ri);
    test_mult_sc(ri);
    return 0;
}