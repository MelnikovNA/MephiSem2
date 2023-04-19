#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "ints.h"
#include "Vector.h"

#define ARRAY_SIZE(foo) (sizeof(foo)/sizeof(foo[0]))

struct test_vector3{
    int x;
    int y;
    int z;
};

struct vectors_t{
    struct test_vector3 a;
    struct test_vector3 b;
    struct test_vector3 res;
    int want_err;
};

struct  vectors_t sum_tests[] = {
        {{ 1,  1,  1},
         { 1,1, 1},
         {2,2, 2},
         false},

        {{1,2, 3},
         {3,2, 1},
         {4,4, 4},
         false},

        {{-10,1, 1},
         {1,1, 1},
         {-9,2, 2},
         false},

        {{-10,1, 1},
         {1,1, 1},
         {-900,2, 2},
         true},
};

struct ints_test{
    int a;
    char *b;
    int want_err;
};

struct  ints_test int_tests[]={
        {-10, "-10", false},
        {0, "0", false},
        {10, "10", false},
        {0, "!aa", true},
};

int tests_strs_to_ints(){
    for(int i = 0; i< ARRAY_SIZE(int_tests); i++){
        void *res = str_to_val_int(int_tests[i].b);
        if(res == NULL){
            if(int_tests[i].want_err == false){
                printf("test #%d failed\n",i);
                exit(1);
            }
            continue;
        }
        int r = *((int*)res);
        if(r ==int_tests[i].a && int_tests[i].want_err == true ||
           r !=int_tests[i].a && int_tests[i].want_err == false){
            printf("test #%d failed\n",i);
            exit(1);
        }
        free(res);
    }
    printf("Tests (str to int) passed\n");
    return 0;
}

int tests_ints_to_strs(){
    for(int i = 0; i < ARRAY_SIZE(int_tests); i++){
        char *res = val_to_str_int((void *)&int_tests[i].a);
        if(strcmp(res, int_tests[i].b) ==0&& int_tests[i].want_err == true || strcmp(res, int_tests[i].b) !=0 && int_tests[i].want_err == false){
            printf("test #%d failed\n", i);
            exit(1);
        }
    }
    printf("Tests (int to str) passed\n");
    return 0;
};

int tests_sum(struct RingInfo* ri){
    struct Vector3 a,b,res;
    for(int i = 0; i< ARRAY_SIZE(sum_tests);i++){
        a.x=&sum_tests[i].a.x;
        a.y=&sum_tests[i].a.y;
        a.z=&sum_tests[i].a.z;

        b.x=&sum_tests[i].b.x;
        b.y=&sum_tests[i].b.y;
        b.z=&sum_tests[i].b.z;

        struct Vector3 *sum = sum_vec(&a, &b, ri);

        bool comp =*(int*) sum->x == sum_tests[i].res.x  &&
                                *(int*) sum->y == sum_tests[i].res.z &&
                                *(int*) sum->z == sum_tests[i].res.z;
        if(comp==true && sum_tests[i].want_err == true ||
        comp==false && sum_tests[i].want_err == false){
            printf("test #%d failed\n",i);
            exit(1);
        }
    }
    printf("Tests (int sum vectors ) passed ");
    return 0;
};

int main(){
    struct RingInfo* ri;
    tests_strs_to_ints();
    tests_ints_to_strs();
    ri= Create(sizeof(int), &sum_int,&mult_int,  &new_int,
               &str_to_val_int, &val_to_str_int);
    tests_sum(ri);
    return 0;
}