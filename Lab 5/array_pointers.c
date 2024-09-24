/* array_pointers.c - SYSC 2006 Lab 5 */

#include <stdlib.h>  
#include <stdio.h>
#include <stdbool.h>

#include "array_pointers.h"


// Exercise 1

/* Return the maximum value in the first n elements of array of integers, ar. 
   If n is less than or equal to 0, it returns 0.  
   This function uses array indices.  Do not change this function. */
int find_max_v0(const int ar[], int n) {
	int max;
	if (n<=0) {
		return 0; // ensure we proceed only if n is reasonable
	}
	max = ar[0];
	for (int i=1; i<n; i++) {
		if (ar[i]>max) {
			max = ar[i];
		}
	}
	return max;
}

/* Return the maximum value in the first n elements of an array of integers. 
   If n is less than or equal to 0, it returns 0.  
   This function uses a pointer to an array. */
int find_max_v1(const int *arp, int n) {

	int max = 0;

	for(int i = 0; i < n; i++){
		int current = *(arp+i);
		if(current > max){
			max = current;
		}
	}

	return max;
}

/* Return the maximum value in the first n elements of an array of integers. 
   If n is less than or equal to 0, it returns 0.  
   This function uses a walking pointer to the array. */
int find_max_v2(const int *arp, int n) {
	int max = 0;

	for(int i = 0; i < n; i++){
		if(*arp > max){
			max = *arp;
		}

		arp += 1;
	}
	return max;
}

// Exercise 2
/* Return the count of the number of times target occurs in the first 
 * n elements of array a.
 */
int count_in_array(int a[], int n, int target)
{
	int count = 0;
	if(n >= 0){
		if(a[n] == target){
			count = 1;
		}
		count += count_in_array(a, n - 1, target);
	}
    return count;
}

// Exercise 3
/* Return true if the first n elements in arr1 and arr2 are equal
and return false otherwise */
_Bool array_compare(int arr1[], int arr2[], int n){

	if(n > 0){
		if(*(arr1) == *(arr2)){
			//Uses pointer arithmetic to count up indexes and counts down n until it hits 1
			return array_compare(arr1 + 1, arr2 + 1, n - 1);
		} else {
			return false;
		}
	}
	return true;
}