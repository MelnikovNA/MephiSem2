#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "ints.h"
#define ARRAY_SIZE(foo) (sizeof(foo)/sizeof(foo[0]))

struct ints_test{
    int a;
    char *b;
    int whant_err;
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
            if( int_tests[i].whant_err ==false){
                printf("test #%d failed\n",i);
                exit(1);
            }
            continue;
        }
        int r = *((int*)res);
        if(r ==int_tests[i].a && int_tests[i].whant_err==true ||
           r !=int_tests[i].a && int_tests[i].whant_err==false){
            printf("test #%d failed\n",i);
            exit(1);
        }
        free(res);
    }

    printf("Tests passed\n");
}

int main(){
    tests_strs_to_ints();
    return 0;
}