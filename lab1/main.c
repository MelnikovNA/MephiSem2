#include <stdio.h>
#include "ints.h"
#include "RingInfo.h"
#include "Vector.h"
#include "double.h"
#include "menu.h"

int main() {
    setbuf(stdout, NULL);

    int types;
    struct RingInfo* ri;
    printf("Data type:\n1-Integer\n2-Real numbers\n");
    scanf("%d", &types);
    switch (types) {
        case 1:
            printf("Integer\n");
            ri= Create(sizeof(int), &sum_int,&mult_int,  &new_int,
                       &str_to_val_int, &val_to_str_int);
            menu(ri);
            break;
        case 2:
            printf("Real numbers\n");
            ri = Create(sizeof(double ), &sum_double, &mult_double,
                        &new_double, &str_to_val_double, &val_to_str_double);
            menu(ri);
            break;
        default:
            printf(  "wrong arg \n");
    }
    return 0;
}
