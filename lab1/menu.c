#include <stdio.h>
#include <string.h>
#include "ints.h"
#include "RingInfo.h"
#include "Vector.h"
#include "double.h"


int menu(struct RingInfo* ri){
    int type, start;
    char temp_file_name[FILENAME_MAX];
    char file_name[FILENAME_MAX];
    struct vectors *vs;
    printf("1 - Input vectors\n2 - Import vectors from file\n");
    scanf("%d", &start);

    switch (start) {
        case 1:
            vs = calloc(1, sizeof(struct vectors));
            vs->ringInfo=ri;
            vs->len = 0;
            vs->capacity = 0;
            printf("enter 1 vector:\n");
            vectors_imput(vs, ri);
            printf("enter 2 vector:\n");
            vectors_imput(vs, ri);
            break;
        case 2:
            printf("Enter the absolute path to the file: ");
            scanf("%s", &file_name);
            vs = from_file(file_name, ri);
            break;
        default:
            printf("wrong arg");
    }
    printf("------------------\n1 - Vector addition\n2-Mult_sc vector\n0-exit\n------------------\n");


    while (1){
        struct Vector3 *res;
        void *result;
        scanf("%d", &type);
        switch (type) {
            case 0:
                exit(0);
            case 1:
                res = sum_vec(vs->v3s[0], vs->v3s[1], ri);
                print_v3(res, ri);
                free(res);
                break;
            case 2:
                result= mult_sc(vs->v3s[0], vs->v3s[1], ri);
                print_val(result, ri);
                free(result);
                break;
            case 5:
                print_vs(vs);
                break;
            default:
                break;
        }
    }
    return 0;
}