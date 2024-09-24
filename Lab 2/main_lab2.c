//SYSC 2006 - Lab 2 Template

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include the necessary header for _Bool
#include "lab2.h"

#define PRIME_TESTS 4
#define SUM_TESTS 5

/* Replace these lines with your information */ 
  const char* author_main = "Nicholas Dorscht"; 
  const char* student_number_main = "101298132"; 

int main(void){
  // Tests exercise 1 - Complete for a comprehensive test harness
  int expected_week_non_vac = 7;
  int expected_week_vac = 10;
  int expected_weekend_vac = -1;
  int alarm_time = 0;
  for(int day = 0; day <=6; day++){
    //Check for weekdays non-vacation
    if(day > 0 && day < 6){
      alarm_time = alarm_clock(day, false);
      if (alarm_time == expected_week_non_vac) {
        printf("Day %d, Non-vacation: TEST PASS.\n", day);
      } else {
        printf("Day %d, Non-vacation: TEST FAIL.\n", day);
      } 
      //vacation
      alarm_time = alarm_clock(day, true);
      if(alarm_time == expected_week_vac){
        printf("Day %d, vacation: TEST PASS.\n", day);
      } else {
        printf("Day %d, vacation: TEST FAIL.\n", day);
      } 
    } else {
      //weekend non vacation
      alarm_time = alarm_clock(day, false);
      if(alarm_time == expected_week_vac){
        printf("Day %d, non-vacation: TEST PASS.\n", day);
      } else {
        printf("Day %d, non-vacation: TEST FAIL.\n", day);
      } 
      //vacation
      alarm_time = alarm_clock(day, true);
      if(alarm_time == expected_weekend_vac){
        printf("Day %d, vacation: TEST PASS.\n", day);
      } else {
        printf("Day %d, vacation: TEST FAIL.\n", day);
      } 
    }
  }

  printf("\n");
  // Type your test cases for exercise 2. Make sure to include border line cases
  //Test 1 should output "1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16"
  count_replace(16);
  //Test 2 should output "\n"
  count_replace(0);
  //Test 3 should output "1 2 Fizz"
  count_replace(3);

  printf("\n");

  // Type your test cases for exercise 3. Make sure to include border line cases
  int test_primes[PRIME_TESTS] = {1, 0, 17, 20};
  _Bool test_primes_ans[PRIME_TESTS] = {false, false, true, false}; 

  for(int i = 0; i < PRIME_TESTS; i++){
    if (is_prime(test_primes[i]) == test_primes_ans[i]) {
          printf("Prime %d: TEST PASS.\n", test_primes[i]);
        } else {
          printf("Prime %d: TEST FAIL.\n", test_primes[i]);
        }
  }

  printf("\n");
  // Type your test cases for exercise 4. Make sure to include border line cases
  int test_sums[SUM_TESTS] = {1, 5, 10, 0, 100};
  int test_sums_ans[SUM_TESTS] = {0, 6, 30, 0, 2550};

  for(int i = 0; i < SUM_TESTS; i++){
    if (sum_even(test_sums[i]) == test_sums_ans[i]) {
          printf("Sum %d: TEST PASS.\n", test_sums[i]);
        } else {
          printf("Sum %d: TEST FAIL.\n", test_sums[i]);
        }
  }

  printf("Test harness finished\n");
  return EXIT_SUCCESS;
}


