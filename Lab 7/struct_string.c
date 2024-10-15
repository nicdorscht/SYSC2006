#include "struct_string.h"
#include <stdlib.h>  // abs(x)
#include <stdio.h>   // printf

// Exercise 1
/* Print fraction pointed to by pf in the form a/b. */
void print_fraction(const fraction_t* pf)
{
   printf("%d/%d", pf->num, pf->den);
}

/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.  Copy this function from Lab 6.  No changes are needed.
*/
int gcd(int a, int b)
{
   /* Euclid's algorithm, using iteration and calculation of remainders. */
   int q = abs(a);
   int p = abs(b);
   int r = q % p;

   while(r != 0){
      q = p;
      p = r;
      r = q % p;
   }

	return p;
}

/* Updates the fraction pointed to by pf to its reduced form.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
	   positive, and the numerator and denominator have no common
	   divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
	   are made positive, or if the numerator is positive and the 
	   denominator is negative, the numerator is made negative and the 
	   denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
	   common divisor. 
*/
void reduce(fraction_t* pf)
{
   int gcden = gcd(pf->num, pf->den);

   if(pf->den < 0){
      pf->den *= -1;
      pf->num *= -1;
   } else if (pf->num == 0){
      pf->den = 1;
      return;
   }

   pf->num /= gcden;
   pf->den /= gcden;
}

/* Returns a pointer to a fraction (by reference) with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form.
*/
void make_fraction(int a, int b, fraction_t* pf)
{
   if(b == 0){
      printf("Denominator cannot be 0");
      exit(1);
   }

   pf->num = a;
   pf->den = b;

   reduce(pf);
}

/* Returns by reference a pointer to the sum of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void add_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* psum)
{
   psum->num = pf1->num * pf2->den + pf1->den * pf2->num;
   psum->den = pf1->den * pf2->den;

   reduce(psum);
}

/* Returns by reference a pointer to the product of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void multiply_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* pprod)
{
   pprod->num = pf1->num * pf2->num;
   pprod->den = pf1->den * pf2->den;

   reduce(pprod);
}

// Exercise 2

/* Update the GPA of the student pointed to by studentp, assuming the student has numGrades.	Note that update_gpa must call calc_gpa for each student. */
void update_gpa(student_t *studentp, int numGrades) {
   studentp->gpa = calc_gpa(&studentp->grades[0], numGrades);
}

/* Calculate the GPA associated with the numGrades pointed to by gradesp.
   The implementation must use a walking pointer. 
   If the total weight of all courses is 0, a GPA of 0 is returned. */
float calc_gpa(const grade_t *gradesp, int numGrades) {

   float total = 0;
   float credits = 0;

   for(int i = 0; i < numGrades; i++){
      total += gradesp->gp * gradesp->weight;
      credits += gradesp->weight;

      gradesp++;
   }
	return total / credits;
}

// Exercise 3

/* Calculate how many time the target character appears in string my_str
For example:
count_char("Hello world ",'l') return 3
count_char("Hello world ",'a') return 0
Your implementation must use array-indexing. 
*/

int count_char(const char * my_str, char target){
   int num = 0;

   int i = 0;

   while(my_str[i] != '\0'){
      if(my_str[i] == target){
         num++;
      }
      i++;
   }
   return num;
}

// Exercise 4

/* Calculate how many time the target character appears in string my_str
For example:
count_char("Hello world ",'l') return 3
count_char("Hello world ",'a') return 0
Your implementation must use walking pointer.
*/


int count_char_wp(const char * my_str, char target){

   int num = 0;
   while(*my_str != '\0'){
      if(*my_str == target){
         num++;
      }

      my_str++;
   }
   return num;
}