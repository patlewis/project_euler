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
 * The idea behind the solution is to keep a running sum of the numbers that
 * qualify.  Since all we're doing is additions, we don't really have to worry 
 * about counting floating-point operations.  We first start with 3, because 
 * that's the first number that qualifies.  We increment the current number by
 * three and then add that number.  Once all of the multiples of three have 
 * been added, we go through all the multiples of five.  If a number is both a 
 * multiple of three and five, then it is skipped during the addition of threes.
 * This way we can avoid branches so that the algorithm runs a lot faster.    
 * We sacrifice a bit of coding elegance for a tad of efficiency. 
 */

 int main(void)
 {
 	int sum3 = 0;
 	int x = 0;
 	//first do multiples of three
 	while(x < 1000)
 	{
 		x += 3; sum3 += x;	printf("%d\n", x);//3
 		x += 3;	sum3 += x;	printf("%d\n", x);//6
 		x += 3; sum3 += x;	printf("%d\n", x);//9
 		x += 3; sum3 += x;	printf("%d\n", x);//12
 		x += 3; printf("skip %d\n", x);//skip the multiple of 5
 	}
 	//now do multiples of 5
 	int sum5;
 	x = 5;
 	while(x < 1000)
 	{
 		sum5 += x;
 		x += 5;
 	}
 	///////////////////////////////////////////////////////////////////////////
 	printf("\n\n");
 	int sum31;
 	sum31 = 0;
 	for (x = 0; x < 1000; x++)
 	{
 		if ( (x%3 == 0) && (x%5 != 0))
 		{
 			printf("%d\n", x);
 			sum31 += x;
 		}
 	}
 	if(sum3 != (sum31)) printf("FUCK(3): %d \t %d\n", sum3, sum31);
 	else
 	{
 		int sum = sum3 + sum5;
		printf("Sum of all multiples of 3 and 5 up to 1000:  %d\n", sum);
 	}
 	return 0;
 }