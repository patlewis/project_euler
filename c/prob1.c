#include <stdio.h>


/*
 * Project Euler problem 1--Multiples of 3 and 5.  The problem description from 
 * the website reads:
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we 
 * get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 *
 * The idea behind the solution is to exploit the summation formula 
 * that Gauss originally came up with.  We use SUM = (n/2)(a + b) where n is the
 * overall number of items, a is the starting number, and b is the ending 
 * number.  For a more robust solution, we would normally use variables for a
 * and b, and somehow find them.  For this situation, we already know that the 
 * starting number will be 3, the ending number will be 999, and the number of 
 * numbers will be 333.  This is just some basic mental math.  
 * 
 * For the sake of this particular problem, we will also use a little set 
 * theory.  In general, the exclusive OR (XOR) of sets A and B is the union of
 * A and B minus the intersection of A and B.  So the set of all numbers that is
 * divisible by 3 or 5 is the set of all numbers divisible by three unioned with
 * the set of all numbers divisible by 5 minus the set of all numbers divisible
 * by 3 and 5.  Since there's really no way to algorithmically figure this out
 * because of the arbitrary problem description, it is just hardcoded in.
 */

int sum(int, int);

 int main(void)
 {
 	int total = sum(999,3) + sum(999,5) - sum(999,15);
	printf("========== Problem 1 ==========\n");
 	printf("Sum = %d\n", total);
	printf("===============================\n");
 	return 0;
 }

/*
 * b is the max number, m is the multiple
 */
 int sum(int b, int m)
 {
 	int n = (int)(b / m); //number of numbers to use
 	// Since we have to account for all numbers being less than b, we have to 
 	// massage the numbers a little bit.  We have to use m * int((1+b)/m) to 
 	// ensure this condition, otherwise we might end up with numbers greater
 	// than b.
 	return (int)(n * m * (1 + n) / 2);
 }
