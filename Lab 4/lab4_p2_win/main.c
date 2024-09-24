#include<stdio.h>
#include<stdlib.h>
#include "lab4test.h"

int variable1;
int main(void){
    variable1 = 0;
    int i = 100;
    for (int i = 0; i < 8; i++){
        printf("The value of variable1 is: %d\n", variable1);
        variable1++;
    }

    i = test1(variable1);

    return EXIT_SUCCESS;
}

/*
1. local
2. no as they are defined in a local scope
3. no, it affects the local variable
4. variable1 is global, and i is local to main
5. there is only one that is global
6. no they are individually defined
*/