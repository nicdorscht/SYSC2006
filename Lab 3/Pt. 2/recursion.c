/* SYSC 2006 Lab 3, part 2. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "recursion.h"



/* Exercise 4. Return the number of digits in integer n, n >= 0. */
int num_digits(int n)
{
    int digits = 1;

    if(n / 10 >= 1){
        digits += num_digits(n/10);
    }

    return digits;
}

/* Exercise 5. Return x raised to the power n for n >= 0. */
double power2(double x, int n){

    int ans = x;

    if(n >= 1){
        ans *= power2(x, n - 1);
    } else if (n == 0){
        ans = 1;
    }

    return ans;
}

