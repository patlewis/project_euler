#include <stdio.h>
#include <math.h>
#include <sys/time.h>

// COMPILER NOTE: The -lm flag must be used during compilation.

/*
 * Project Euler Problem 2
 * 
 * Each new term in the Fibonacci sequence is generated by adding the previous 
 * two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not exceed
 * four million, find the sum of the even-valued terms.
 * 
 * My solution is very simple.  It's iterative, meaning it's not exactly speedy,
 * but it does get the right answer, and it's easy to understand.  It goes 
 * through all Fibonacci numbers less than 4000000, and if they are even, adds
 * them to a running sum.
 */

 double fibo_iter(int);
 double fibo_with_phi(int);

 int main(void)
 {
  	printf("Iterative solution:\t\t ");
 	double t1 = fibo_iter(4000000);
 	printf("Multiplicative solution:\t ");
 	double t2 = fibo_with_phi(4000000);	

 	printf("\n\n");

 	printf("The following times were taken using an adapatation of the     \n");
 	printf("\"gettimeofday()\" function in <sys\\time.h>.  The resolution  \n");
 	printf("isn't spectacular, but it functions as a rough guide for the   \n");
 	printf("execution times of the two functions, and it serves our needs. \n");

	printf("\n");

	printf("Iterative solution time:\t%f\n", t1);
	printf("Multiplicative solution time:\t%f\n", t2);

	return 0;
 }

/*
 * The boring, somewhat naive but technically correct solution. It's iterative.
 * I'm a little disappointed in myself.
 */
double fibo_iter(int max)
{
	//start timing
	struct timeval start, end;
	gettimeofday(&start, NULL);
	
 	int sum  = 0; 
 	int curr = 2;
 	int prev = 1;
 	int temp;		//only used when setting the next fibonacci number
 	while(curr <= max)
 	{
 		//if even, add to sum
 		if(curr % 2 == 0) sum += curr;
 		temp = curr;
 		curr += prev;
 		prev = temp;
 	}
 	
 	//end timing
 	gettimeofday(&end, NULL);
	long secs, usecs;
	double mtime;
	secs = end.tv_sec - start.tv_sec;
	usecs = end.tv_usec  - start.tv_usec;
	mtime = secs + ((double) usecs)/1000;
	
	printf("Sum = %d\n", sum);
 	
 	return mtime;
}
/*
 * The idea behind this is that the ratio between two numbers in the Fibonacci
 * sequence is the Golden Ratio, phi.  Additional insight is that every third 
 * number is even, which is easy enough to prove by induction.  Using that, the
 * ratio between every even number in the sequence is phi^3.  So we just 
 * mulitply by that each time and then we don't have to worry about checking all
 * the odd numbers cause we already know that we need to add this number.
 * 
 * Seeing as it does not iterate through all the Fibonnaci numbers, it would 
 * seem to be quite a bit faster.  However, floating-point operations aren't 
 * exactly the quickest, so I'm not sure how that would impact the overall
 * calculation. I would have liked to have done it without any branches, but the
 * nature of numerical math made that a little rough.
 */
 double fibo_with_phi(int max)
 {
 	//start timing
	struct timeval start, end;
	gettimeofday(&start, NULL);

 	double phi = (1 + sqrt(5))/2;
 	int num = 2;
 	int sum = 0;
 	double tmp;
 	while(num <= max)
 	{
 		sum += num;
 		//Because of the nature of decimals, we will be getting a decimal out
 		// of the next calculation.  We'll have to make it an even integer, not
 		// just any integer, so it'll take some slightly inelegant work.
 		tmp = (int)(num * pow(phi, 3));
 		tmp = floor(tmp);
 		if((int)tmp % 2 == 0) num = tmp; //if already even, do nothing
 		else num = tmp +1;			//if odd, have to round up
 		
 	}
 	
 	//end timing
 	gettimeofday(&end, NULL);
	long secs, usecs;
	double mtime;
	secs = end.tv_sec - start.tv_sec;
	usecs = end.tv_usec  - start.tv_usec;
	mtime = secs + ((double) usecs)/1000;

	printf("Sum = %d\n", sum);

 	return mtime;
 }
